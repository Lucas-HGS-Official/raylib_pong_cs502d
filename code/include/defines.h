#ifndef DEFINES_H
#define DEFINES_H

#include <raylib.h>

#include "flecs.h"


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450
#define WINDOW_NAME "Ray Pong!"
#define BG_COLOR (Color) { 40, 60, 60, 255 }

#define PADDLE_SPEED 250

enum FontSizes {
    SMALL_FONT = 16,
    LARGE_FONT = 32,
    SCORE_FONT = 64,
};

enum GameStates {
    START_STATE,
    SERVE_STATE,
    PLAY_STATE,
    GAME_OVER_STATE,
};


extern enum GameStates game_state;

extern ecs_world_t* world_flecs;

extern Font pixeledted_font;

extern int serving_player;

extern int player_1_score;
extern int player_2_score;

extern int winning_player;

// Entities
extern ecs_entity_t paddle_left;
extern ecs_entity_t paddle_right;
extern ecs_entity_t ball;

// Tags
extern ecs_entity_t Player;
extern ecs_entity_t Player_1;
extern ecs_entity_t Player_2;

// 49 lines

#endif
