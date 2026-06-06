#pragma once

#include "flecs.h"

typedef struct UI_Text {
    char* text;
    int size;
} UI_Text;

ECS_COMPONENT_DECLARE(UI_Text);
