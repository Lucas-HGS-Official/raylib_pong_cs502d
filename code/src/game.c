#include "game.h"

#include "flecs.h"
#include <raylib.h>
#include <stdio.h>

#include "define.h"

typedef struct Label {
    char* text;
    int size;
} Label;

ECS_COMPONENT_DECLARE(Label);

static ecs_world_t *world_flecs = NULL;

void component_manager_init(ecs_world_t *world);
void system_manager_init(ecs_world_t *world);
void entity_manager_init(ecs_world_t *world);

static inline void _init_raylib(void);
static inline void _init_flecs(void);
static inline void _init_managers(void);

void ui_text(ecs_iter_t *it);

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
    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        float delta = GetFrameTime();
        running = ecs_progress(world_flecs, delta);
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



void component_manager_init(ecs_world_t *world) {
    ECS_COMPONENT_DEFINE(world, Label);
}
void system_manager_init(ecs_world_t *world) {
    ECS_SYSTEM(world, ui_text, EcsOnUpdate, Label);
}
void entity_manager_init(ecs_world_t *world) {
    ecs_entity_t text_test = ecs_entity(world_flecs, { .name="Test" });
    ecs_set(world_flecs, text_test, Label, {
        .text = "Hello World!",
        .size = 22,
    });
    if (ecs_is_alive(world_flecs, text_test)) { printf("\ntest\n\n"); }

}

void ui_text(ecs_iter_t *it) {
    // while (ecs_iter_next(it)) {
        Label *labels = ecs_field(it, Label, 0);

        for (int i=0; i<it->count; i++) {
            Label label = labels[i];
            // BeginDrawing();
            // ClearBackground(RAYWHITE);
            DrawText(label.text, 0, 0, label.size, BLACK);
            // EndDrawing();
        // }
    }
}
