#ifndef BALL_H
#define BALL_H

#include <stdbool.h>

#include <raylib.h>


#define BALL_WIDTH 13
#define BALL_HEIGHT BALL_WIDTH

typedef struct ball_t {
    Rectangle rec;
    Vector2 Dxy;
} ball_t;


ball_t * ball_init();
void ball_render(ball_t *ball);
void ball_update(ball_t *ball);
void ball_delete(ball_t *ball);
void ball_reset(ball_t *ball);

#endif
