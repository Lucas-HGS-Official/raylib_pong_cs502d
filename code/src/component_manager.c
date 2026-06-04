#include "component_manager.h"

#include "Paddle.h"

void component_manager_init(ecs_world_t *world) {
    ECS_COMPONENT_DEFINE(world, Paddle);
}
