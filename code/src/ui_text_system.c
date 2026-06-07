#include "ui_text_system.h"

#include "label_component.h"
#include <raylib.h>

void ui_text(ecs_iter_t *it) {
    while (ecs_iter_next(it)) {
        Label* labels = ecs_field(it, Label, 0);

        for (int i=0; i<it->count; i++) {
            Label label = labels[i];
            // BeginDrawing();
            // ClearBackground(RAYWHITE);
            DrawText(label.text, 0, 0, label.size, BLACK);
            // EndDrawing();
        }
    }
}
