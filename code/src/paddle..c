#include "paddle.h"

#include <stdlib.h>

#include <raylib.h>


typedef struct paddle_t {
    Rectangle rec;
    Vector2 direction;
    float speed;
} paddle_t;


paddle_t *paddle_init(paddle_t *paddle, Vector2 initial_pos) {
    paddle = (paddle_t*) MemAlloc(sizeof(paddle_t));
    paddle->rec = (Rectangle) {
        .height = PADDLE_HEIGHT,
        .width = PADDLE_WIDTH,
        .x = initial_pos.x,
        .y = initial_pos.y,
    };
    paddle->direction = (Vector2) {
        .x = 0.f,
        .y = 0.f,
    };
    paddle->speed = 0.f;

    return paddle;
}

void paddle_render(paddle_t *paddle) {
    DrawRectangleRec(paddle->rec, RAYWHITE);

    return;
}

void paddle_delete(paddle_t *paddle) {
    MemFree(paddle);

    paddle = NULL;

    return;
}
