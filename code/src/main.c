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
int top_text_pair(const char* upper_text, const char* lower_text, int text_size);


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
            top_text_pair("Welcome to Pong!", "Press Enter to begin!", SMALL_FONT);

            break;
        }

        case SERVE_STATE: {
            top_text_pair(TextFormat("Player %d's serve", serving_player), "Press Enter to serve!", SMALL_FONT);

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

int top_text_pair(const char* upper_text, const  char* lower_text, int text_size) {
    const int text_padding_up = 10;

    Vector2 size_upper_text = MeasureTextEx(pixeledted_font, upper_text, text_size, 0.f);
    Vector2 pos_upper_text = { .x = (WINDOW_WIDTH/2.f) - (size_upper_text.x/2.f), .y = text_padding_up };
    DrawTextEx(pixeledted_font, upper_text, pos_upper_text, text_size, 0.f, WHITE);

    Vector2 size_lower_text = MeasureTextEx(pixeledted_font, lower_text, text_size, 0.f);
    Vector2 pos_lower_text = { .x = (WINDOW_WIDTH/2.f) - (size_lower_text.x/2.f), .y = text_padding_up + size_upper_text.y };
    DrawTextEx(pixeledted_font, lower_text, pos_lower_text, text_size, 0.f, WHITE);

    return 0;
}
