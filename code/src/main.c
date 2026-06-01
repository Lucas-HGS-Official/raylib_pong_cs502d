#include <raylib.h>
#include <stdio.h>

#include "defines.h"


Font pixeledted_font;

int game_init(void);
int game_mainloop(void);
int game_close(void);

int game_draw(void);
int game_update(void);


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
    CloseWindow();

    return 0;
}


int game_update(void) {

    return 0;
}

int game_draw(void) {
    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTextEx(pixeledted_font,"Congrats! You created your first window!", (Vector2) {190, 200}, SCORE_FONT,1, LIGHTGRAY);

    EndDrawing();

    return 0;
}
