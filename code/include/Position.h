#pragma once

#include "flecs.h"

typedef struct Position {
    float x;
    float y;
} Position;

ECS_COMPONENT_DECLARE(Position);
