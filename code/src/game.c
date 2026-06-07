#include "game.h"

#include "flecs.h"
#include <raylib.h>

#include "define.h"

#include "component_manager.h"
#include "system_manager.h"
#include "entity_manager.h"


static ecs_world_t *world_flecs = NULL;

static inline void _init_raylib(void);
static inline void _init_flecs(void);
static inline void _init_managers(void);

void game_manager_init(void) {
    _init_raylib();
    _init_flecs();
    _init_managers();
}
static inline void _init_raylib(void) {
    int flags = FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE;
    SetConfigFlags(flags);
    SetTargetFPS(60);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_NAME);
}
static inline void _init_flecs(void) {
    world_flecs = ecs_init();
}
static inline void _init_managers(void) {
    component_manager_init(world_flecs);
    entity_manager_init(world_flecs);
    system_manager_init(world_flecs);
}


void game_manager_loop(void) {
    bool running = true;
    bool started = false;
    float time = 0;
    if (!IsWindowReady())
        return;
    while (running) {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        float delta = GetFrameTime();
        running = ecs_progress(world_flecs, 0);
        time += delta;
        if (!started && time > delta) {
            started = true;
        }
        EndDrawing();
    }
}

void game_manager_fini(void) {
    CloseWindow();
    ecs_fini(world_flecs);
}
