#ifndef PADDLE_H
#define PADDLE_H

#include <raylib.h>


#define PADDLE_SPEED 250
#define PADDLE_HEIGHT 60
#define PADDLE_WIDTH 15


typedef struct paddle_t paddle_t;


paddle_t *create_paddle(paddle_t *paddle, Vector2 initial_pos);
void draw_paddle(paddle_t *paddle);
void destroy_paddle(paddle_t *paddle);

#endif
