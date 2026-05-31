#include <raylib.h>


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450
#define WINDOW_NAME "Ray Pong!"

#define PADDLE_SPEED 250

int game_init(void);
int game_update(void);
int game_close(void);
int game_draw(void);


int main(void) {

    game_init();
    game_update();
    game_close();

    return 0;
}


int game_init(void) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);

    SetTargetFPS(60);

    return 0;
}

int game_update(void) {
    while (!WindowShouldClose()) {
        // Update
        //----------------------------------------------------------------------------------

        //----------------------------------------------------------------------------------

        game_draw();
    }

    return 0;
}

int game_close(void) {
    CloseWindow();

    return 0;
}


int game_draw(void) {
    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();

    return 0;
}
