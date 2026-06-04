#ifndef DRAW_PLAYER_SYSTEM_H
#define DRAW_PLAYER_SYSTEM_H

#include "flecs.h"

int init_draw_player_system(void);
void draw_players(ecs_iter_t *it);

#endif
