#include <raylib.h>

#include "defines.h"
#include "paddle.h"
#include "ball.h"


paddle_t *paddle_1 = (paddle_t*) {};
paddle_t *paddle_2 = (paddle_t*) {};
ball_t *ball = (ball_t*) {};


enum GameStates game_state;

Font pixeledted_font = (Font) {};

int serving_player = 0;

int player_1_score = 0;
int player_2_score = 0;

int winning_player = 0;


void game_init(void);
void game_loop(void);
void game_close(void);

void update_game(void);
void draw_game(void);

void top_text_pair(const char *upper_text, const  char *lower_text, int text_size);
void display_score(void);
Vector2 draw_centralized_text(const char *text, int y_pos, int text_size);


int main(void) {
    game_init();
    game_loop();
    game_close();

    return 0;
}


void game_init(void) {
    InitWindow(GAME_WIDTH, GAME_HEIGHT, GAME_NAME);
    SetTargetFPS(60);

    pixeledted_font = LoadFont("resources/fonts/font.ttf");

    // sounds = {
    //     ["paddle_hit"] = love.audio.newSource("sounds/paddle_hit.wav", "static"),
    //     ["score"] = love.audio.newSource("sounds/score.wav", "static"),
    //     ["wall_hit"] = love.audio.newSource("sounds/wall_hit.wav", "static")
    // }

    player_1_score = 0;
    player_2_score = 0;

    paddle_1 = paddle_init((Vector2) { .x=PADDLE_WIDTH, .y=20 });
    paddle_2 = paddle_init((Vector2) { .x=GAME_WIDTH -(PADDLE_WIDTH*2), .y=GAME_HEIGHT - (PADDLE_HEIGHT+20) });

    ball = ball_init();

    serving_player = 1;

    game_state = START_STATE;

    return;
}
void game_loop(void) {
    while (!WindowShouldClose()) {
        update_game();
        draw_game();
    }

    return;
}
void game_close(void) {
    UnloadFont(pixeledted_font);
    pixeledted_font = (Font) {};

    paddle_delete(paddle_1);
    paddle_delete(paddle_2);

    ball_delete(ball);

    CloseWindow();

    return;
}


void update_game(void) {
    switch (game_state) {
        case START_STATE:
            if (IsKeyPressed(KEY_ENTER)) game_state = SERVE_STATE;
        break;

        case SERVE_STATE:
            if (IsKeyPressed(KEY_ENTER)) game_state = PLAY_STATE;

            ball->Dxy.y = GetRandomValue(-50, 50);
            int rand_serv_x = GetRandomValue(140, 200);
            if (serving_player == 1) ball->Dxy.x = rand_serv_x;
            if (serving_player == 2) ball->Dxy.x = -rand_serv_x;
        break;

        case PLAY_STATE:
            if (CheckCollisionRecs(ball->rec, paddle_1->rec)) {
                ball->Dxy.x = -ball->Dxy.x * 1.03;
                ball->rec.x = paddle_1->rec.x + BALL_WIDTH;

                int rand_ball_y = GetRandomValue(10, 150);
                if (ball->Dxy.y < 0) {
                    ball->Dxy.y = -rand_ball_y;
                } else {
                    ball->Dxy.y = rand_ball_y;
                }

                // sounds["paddle_hit"]:play()
            }

            if (CheckCollisionRecs(ball->rec, paddle_2->rec)) {
                ball->Dxy.x = -ball->Dxy.x * 1.03;
                ball->rec.x = paddle_2->rec.x - BALL_WIDTH;

                int rand_ball_y = GetRandomValue(10, 150);
                if (ball->Dxy.y < 0) {
                    ball->Dxy.y = -rand_ball_y;
                } else {
                    ball->Dxy.y = rand_ball_y;
                }

                // sounds["paddle_hit"]:play()
            }

            if (ball->rec.y <= 0) {
                ball->rec.y = 0;
                ball->Dxy.y = -ball->Dxy.y;
                // sounds["wall_hit"]:play()
            }

            if (ball->rec.y >= GAME_HEIGHT - BALL_HEIGHT) {
                ball->rec.y = GAME_HEIGHT - BALL_HEIGHT;
                ball->Dxy.y = -ball->Dxy.y;
                // sounds["wall_hit"]:play()
            }

            if (ball->rec.x < -BALL_WIDTH) {
                serving_player = 1;
                player_2_score++;
                // sounds["score"]:play()
                if (player_2_score == 2) {
                    winning_player = 2;
                    game_state = GAME_OVER_STATE;
                } else {
                    game_state = SERVE_STATE;
                    ball_reset(ball);
                }
            }

            if (ball->rec.x > GAME_WIDTH) {
                serving_player = 2;
                player_1_score++;
                // sounds["score"]:play()
                if (player_1_score == 2) {
                    winning_player = 1;
                    game_state = GAME_OVER_STATE;
                } else {
                    game_state = SERVE_STATE;
                    ball_reset(ball);
                }
            }
        break;

        case GAME_OVER_STATE:
            if (IsKeyPressed(KEY_ENTER)) game_state = SERVE_STATE;
            ball_reset(ball);
            player_1_score = 0;
            player_2_score = 0;
            if (winning_player == 1) serving_player = 2;
            else serving_player = 1;
        break;
    }

    // if (IsKeyDown(KEY_W)) paddle_1->dY = -PADDLE_SPEED;
    // if (IsKeyDown(KEY_S)) paddle_1->dY = +PADDLE_SPEED;
    // else paddle_1->dY = 0;
    paddle_1->dY = (-PADDLE_SPEED * (float)IsKeyDown(KEY_W)) + (+PADDLE_SPEED * (float)IsKeyDown(KEY_S));

    // if (IsKeyDown(KEY_UP)) paddle_2->dY = -PADDLE_SPEED;
    // if (IsKeyDown(KEY_DOWN)) paddle_2->dY = +PADDLE_SPEED;
    // else paddle_2->dY = 0;
    paddle_2->dY = (-PADDLE_SPEED * (float)IsKeyDown(KEY_UP)) + (+PADDLE_SPEED * (float)IsKeyDown(KEY_DOWN));

    if (game_state == PLAY_STATE) ball_update(ball);

    paddle_update(paddle_1);
    paddle_update(paddle_2);

    return;
}
void draw_game(void) {
    BeginDrawing();
    ClearBackground(BG_COLOR);

    switch (game_state) {
        case START_STATE:
            top_text_pair("Welcome to Pong!", "Press Enter to begin!", SMALL_FONT);
        break;

        case SERVE_STATE:
            top_text_pair(TextFormat("Player %d's serve", serving_player), "Press Enter to serve!", SMALL_FONT);
        break;

        case PLAY_STATE:
            // draw_centralized_text("Playing!!", 10, LARGE_FONT);
        break;

        case GAME_OVER_STATE:
            draw_centralized_text(TextFormat("Player %d wins!", winning_player), 10, LARGE_FONT);
        break;
    }
    display_score();

    // DrawLine(GAME_WIDTH/2.f, 0, GAME_WIDTH/2.f, GAME_HEIGHT, RAYWHITE);

    paddle_render(paddle_1);
    paddle_render(paddle_2);

    ball_render(ball);

    EndDrawing();

    return;
}


void top_text_pair(const char *upper_text, const  char *lower_text, int text_size) {
    const int text_padding_up = 10;
    Vector2 upper_text_size = draw_centralized_text(upper_text, text_padding_up, text_size);
    draw_centralized_text(lower_text, upper_text_size.y + text_padding_up, text_size);

    return;
}

Vector2 draw_centralized_text(const char *text, int y_pos, int text_size)  {
    Vector2 size_text = MeasureTextEx(pixeledted_font, text, text_size, 0.f);
    Vector2 pos_text = { .x = (GAME_WIDTH/2.f) - (size_text.x/2.f), .y = y_pos };
    DrawTextEx(pixeledted_font, text, pos_text, text_size, 0.f, WHITE);

    return size_text;
}

void display_score(void) {
    draw_centralized_text(TextFormat("%d %d", player_1_score, player_2_score), GAME_HEIGHT / 3.f, SCORE_FONT);

    return;
}
