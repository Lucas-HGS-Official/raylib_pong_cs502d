#include "defines.h"
#include <raylib.h>
#include <stdio.h>


enum GameStates game_state = 0;

Font pixeledted_font = (Font){};

int serving_player = 0;

int player_1_score = 0;
int player_2_score = 0;


int game_init(void);
int game_mainloop(void);
int game_close(void);

int game_draw(void);
int game_update(void);

int display_score(void);


int main(void) {

    game_init();
    game_mainloop();
    game_close();

    return 0;
}


int game_init(void) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);

    pixeledted_font = LoadFont("resources/fonts/font.ttf");

    // TODO: Load all the sounds in a list

    SetTargetFPS(60);

    // TODO: Create both players paddles
    // TODO: Create the ball

    serving_player = 1;
    game_state = START_STATE;

    return 0;
}

int game_mainloop(void) {
    while (!WindowShouldClose()) {
        game_update();
        game_draw();
    }

    return 0;
}

int game_close(void) {
    UnloadFont(pixeledted_font);
    CloseWindow();

    return 0;
}


int game_update(void) {

    return 0;
}

int game_draw(void) {
    BeginDrawing();

    ClearBackground(BG_COLOR);
    switch (game_state) {
        case PLAY_STATE:
        break;

        case START_STATE: {
            const int text_padding_up = 10;

            const char* welcome_text = "Welcome to Pong!";
            Vector2 size_welcome_text = MeasureTextEx(pixeledted_font, welcome_text, SMALL_FONT, 0.f);
            Vector2 pos_welcome_text = { .x = (WINDOW_WIDTH/2.f) - (size_welcome_text.x/2.f), .y = text_padding_up };
            DrawTextEx(pixeledted_font, welcome_text, pos_welcome_text, SMALL_FONT, 0.f, WHITE);

            const char* press_enter_text = "Press Enter to begin!";
            Vector2 size_press_enter_text = MeasureTextEx(pixeledted_font, press_enter_text, SMALL_FONT, 0.f);
            Vector2 pos_press_enter_text = { .x = (WINDOW_WIDTH/2.f) - (size_press_enter_text.x/2.f), .y = text_padding_up + size_welcome_text.y };
            DrawTextEx(pixeledted_font, press_enter_text, pos_press_enter_text, SMALL_FONT, 0.f, WHITE);

            break;
        }

        case SERVE_STATE: {
            const int text_padding_up = 10;

            const char* serving_player_text = TextFormat("Player %d's serve", serving_player);
            Vector2 size_serving_player_text = MeasureTextEx(pixeledted_font, serving_player_text, SMALL_FONT, 0.f);
            Vector2 pos_serving_player_text = { .x = (WINDOW_WIDTH/2.f) - (size_serving_player_text.x/2.f), .y = text_padding_up };
            DrawTextEx(pixeledted_font, serving_player_text, pos_serving_player_text, SMALL_FONT, 0.f, WHITE);

            const char* press_enter_text = "Press Enter to serve!";
            Vector2 size_press_enter_text = MeasureTextEx(pixeledted_font, press_enter_text, SMALL_FONT, 0.f);
            Vector2 pos_press_enter_text = { .x = (WINDOW_WIDTH/2.f) - (size_press_enter_text.x/2.f), .y = text_padding_up + size_serving_player_text.y };
            DrawTextEx(pixeledted_font, press_enter_text, pos_press_enter_text, SMALL_FONT, 0.f, WHITE);

            break;
        }

        case GAME_OVER_STATE: {

            // TODO: GAME_OVER_STATE

            break;
        }

    }



    display_score();

    EndDrawing();

    return 0;
}


int display_score(void) {

    Vector2 text_size = MeasureTextEx(pixeledted_font, TextFormat("%d", player_1_score), SCORE_FONT, 0.f);

    Vector2 player_1_score_pos = {
        .x = (WINDOW_WIDTH / 2.f) - (text_size.x / 2.f)-(13 + 10),
        .y = WINDOW_HEIGHT / 3.f,
    };

    Vector2 player_2_score_pos = {
        .x = (WINDOW_WIDTH / 2.f) + 10,
        .y = WINDOW_HEIGHT / 3.f,
    };


    DrawTextEx(pixeledted_font, TextFormat("%d", player_1_score), player_1_score_pos, SCORE_FONT, 0.F, WHITE);

    DrawTextEx(pixeledted_font, TextFormat("%d", player_2_score), player_2_score_pos, SCORE_FONT, 0.F, WHITE);

    return 0;
}

// 112 lines
