#include "paddle.h"
#include "defines.h"

#include <stdlib.h>

#include <raylib.h>
#include <raymath.h>

paddle_t *paddle_init(Vector2 initial_pos) {
    paddle_t *paddle = (paddle_t*) MemAlloc(sizeof(paddle_t));
    paddle->rec = (Rectangle) {
        .height = PADDLE_HEIGHT,
        .width = PADDLE_WIDTH,
        .x = initial_pos.x,
        .y = initial_pos.y,
    };
    paddle->dY = 0.f;

    return paddle;
}

void paddle_render(paddle_t *paddle) {
    DrawRectangleRec(paddle->rec, RAYWHITE);

    return;
}

void paddle_update(paddle_t *paddle) {
    paddle->rec.y = Clamp(paddle->rec.y + (paddle->dY * GetFrameTime()), 0, GAME_HEIGHT - paddle->rec.height);

    return;
}

void paddle_delete(paddle_t *paddle) {
    MemFree(paddle);

    paddle = NULL;

    return;
}
