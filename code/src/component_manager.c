#include "component_manager.h"

#include "label_component.h"

ECS_COMPONENT_DECLARE(Label);

void component_manager_init(ecs_world_t *world) {
    ECS_COMPONENT_DEFINE(world, Label);
}
