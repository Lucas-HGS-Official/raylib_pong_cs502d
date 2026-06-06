#include "system_manager.h"

#include "ui_text_system.h"

void system_manager_init(ecs_world_t *world) {
    ECS_SYSTEM(world, ui_text, EcsOnUpdate);
}
