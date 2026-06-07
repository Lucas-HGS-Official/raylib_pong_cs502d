#ifndef LABEL_COMPONENT_H
#define LABEL_COMPONENT_H

#include "flecs.h"

typedef struct Label {
    char* text;
    int size;
} Label;

extern ECS_COMPONENT_DECLARE(Label);

#endif
