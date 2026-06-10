#include <raylib.h>

#include "defines.h"
#include "paddle.h"


paddle_t *paddle_1 = (paddle_t*) {};
paddle_t *paddle_2 = (paddle_t*) {};


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

void update_start_state(void);
void update_serve_state(void);
void update_play_state(void);
void update_game_over_state(void);

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

    //TODO: do audio stuff

    player_1_score = 0;
    player_2_score = 0;

    paddle_1 = paddle_init((Vector2) { .x=PADDLE_WIDTH, .y=20 });
    paddle_2 = paddle_init((Vector2) { .x=GAME_WIDTH -(PADDLE_WIDTH*2), .y=GAME_HEIGHT - (PADDLE_HEIGHT+20) });

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

    CloseWindow();

    return;
}


void update_game(void) {
    switch (game_state) {
        case START_STATE:
            update_start_state();
        break;

        case SERVE_STATE:
            update_serve_state();
        break;

        case PLAY_STATE:
            update_play_state();
        break;

        case GAME_OVER_STATE:
            update_game_over_state();
        break;
    }

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
            draw_centralized_text("Playing!!", 10, LARGE_FONT);
        break;

        case GAME_OVER_STATE:
            draw_centralized_text(TextFormat("Player %d wins!", winning_player), 10, LARGE_FONT);
        break;
    }
    display_score();

    paddle_render(paddle_1);
    paddle_render(paddle_2);

    EndDrawing();

    return;
}


void update_start_state(void) {
    if (IsKeyPressed(KEY_ENTER)) game_state = SERVE_STATE;

    return;
}
void update_serve_state(void) {
    if (IsKeyPressed(KEY_ENTER)) game_state = PLAY_STATE;

    return;
}
void update_play_state(void) {
    if (IsKeyPressed(KEY_ENTER)) game_state = GAME_OVER_STATE;

    return;
}
void update_game_over_state(void) {
    if (IsKeyPressed(KEY_ENTER)) game_state = START_STATE;

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
