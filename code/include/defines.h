#ifndef DEFINES_H
#define DEFINES_H

#include <raylib.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define GAME_WIDTH 854
#define GAME_HEIGHT 480

#define GAME_NAME "Raylib CS50 2D Pong."

#define BG_COLOR (Color) {40, 60, 60, 255}

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

extern Font pixeledted_font;

extern int serving_player;

extern int player_1_score;
extern int player_2_score;

extern int winning_player;

#endif
