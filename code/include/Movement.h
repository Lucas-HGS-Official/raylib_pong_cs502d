#pragma once

#include <raylib.h>
#include "flecs.h"

typedef struct Movement {
    Vector2 direction;
    float speed;
} Movement;

ECS_COMPONENT_DECLARE(Movement);
