#include "draw_player_system.h"

#include "flecs.h"
#include <raylib.h>

#include "defines.h"

// #include "Paddle.h"

int init_draw_player_system(void) {
    ECS_SYSTEM(world_flecs, draw_players, EcsOnUpdate, Paddle);

    return 0;
}

void draw_players(ecs_iter_t *it) {
    Paddle* recs = ecs_field(it, Paddle, 0);

    for (int i=0; i<it->count; i++) {
        Rectangle rec = recs[i];
        DrawRectangleRec(rec, RAYWHITE);
    }

    return;
}
