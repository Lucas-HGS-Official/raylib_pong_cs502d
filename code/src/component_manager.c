#include "component_manager.h"

#include "ui_text_component.h"

void component_manager_init(ecs_world_t *world) {
    ECS_COMPONENT_DEFINE(world, UI_Text);
}
