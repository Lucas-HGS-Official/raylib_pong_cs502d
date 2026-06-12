#include "ball.h"

#include <stdbool.h>
#include <stdlib.h>

#include <raylib.h>

#include "defines.h"


#define BALL_INITIAL_X (GAME_WIDTH/2.f)-(BALL_WIDTH/2.f)
#define BALL_INITIAL_Y (GAME_HEIGHT/2.f)-(BALL_HEIGHT/2.f)


ball_t * ball_init() {
    ball_t *ball = (ball_t*)MemAlloc(sizeof(ball_t));
    ball->rec = (Rectangle) {
        .height = BALL_HEIGHT,
        .width = BALL_WIDTH,
        .x = BALL_INITIAL_X,
        .y = BALL_INITIAL_Y,
    };
    ball->Dxy = (Vector2) {
        .x = 0.f,
        .y = 0.f,
    };

    return ball;
}

void ball_render(ball_t *ball) {
    DrawRectangleRec(ball->rec, RAYWHITE);

    return;
}

void ball_update(ball_t *ball) {
    ball->rec.x = ball->rec.x + ball->Dxy.x * GetFrameTime();
    ball->rec.y = ball->rec.y + ball->Dxy.y * GetFrameTime();

    return;
}

void ball_delete(ball_t *ball) {
    MemFree(ball);
    ball = NULL;

    return;
}

void ball_reset(ball_t *ball) {
    ball->rec.x = BALL_INITIAL_X;
    ball->rec.y = BALL_INITIAL_Y;

    return;
}
