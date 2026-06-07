#include "entity_manager.h"
#include "label_component.h"

void entity_manager_init(ecs_world_t *world) {
    ecs_entity_t text_test = ecs_new(world);
    ecs_set(world, text_test, Label, {
        .text = "Hello World!",
        .size = 22,
    });
}
