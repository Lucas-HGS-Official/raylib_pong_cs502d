#include <raylib.h>

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

extern Font pixeledted_font;

extern int serving_player;

extern int player_1_score;
extern int player_2_score;

// 26 lines
