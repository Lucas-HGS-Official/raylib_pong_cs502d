#include <raylib.h>
#include <stdio.h>

#include "defines.h"


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
    game_state = START;

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
        ClearBackground((Color) {40, 60, 60, 255});

        display_score();

        DrawTextEx(pixeledted_font,"Congrats! You created your first window!", (Vector2) {190, 200}, LARGE_FONT, 1, LIGHTGRAY);

    EndDrawing();

    return 0;
}


int display_score(void) {

    Vector2 player_1_score_pos = {
        .x = (WINDOW_WIDTH / 2.f) - (MeasureTextEx(pixeledted_font, TextFormat("%d", player_1_score), SCORE_FONT, 0.F).x),
        .y = WINDOW_HEIGHT / 3.f,
    };

    Vector2 player_2_score_pos = {
        .x = (WINDOW_WIDTH / 2.f) + 7,
        .y = WINDOW_HEIGHT / 3.f,
    };
    // TODO: Think of a better way to position the scores


    DrawTextEx(pixeledted_font, TextFormat("%d", player_1_score), player_1_score_pos, SCORE_FONT, 0.F, WHITE);

    DrawLine(WINDOW_WIDTH / 2.f, 0, WINDOW_WIDTH / 2.f, WINDOW_HEIGHT, BLACK);

    DrawTextEx(pixeledted_font, TextFormat("%d", player_2_score), player_2_score_pos, SCORE_FONT, 0.F, WHITE);

    return 0;
}
