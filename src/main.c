#include <stdio.h>

#include "raylib.h"
#include "src/imsogui.h"

int main() {
    const int screenWidth = 500;
    const int screenHeight = 500;
    const int fontSize = 30;
    const Color fontColor = BLACK;
    const int fps = 60;
    const char* text = "Button";
    const int padding = 15;

    InitWindow(screenWidth, screenHeight, "Window\n");

    SetTargetFPS(fps);

    int width = 250;
    int height = 250;
    Rectangle rect = {
        .x = (screenWidth / 2.0f) - (width / 2.0f),
        .y = screenWidth / 2.0f - (height / 2.0f),
        .width = width,
        .height = height,
    };

    Rectangle rect2 = {
        .x = 0,
        .y = 0,
        .width = width,
        .height = height,
    };

    IMSOGUI_context ui = {
        .hot.item = -1,
        .active.item = -1,
    };

    IMSOGUI_id id = {
        .item = 0,
    };
    IMSOGUI_id id2 = {
        .item = 1,
    };

    int textLength = MeasureText(text, fontSize);
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            Vector2 mousePosition = GetMousePosition();

            bool res = imsogui_dobutton(&ui, id, rect);
            if (res == true) {
                printf("button1 has been pressed\n");
            }
            res = imsogui_dobutton(&ui, id2, rect2);
            if (res == true) {
                printf("button2 has been pressed\n");
            }
            DrawText(text, (screenWidth / 2) - (textLength / 2), screenHeight / 2, fontSize, fontColor);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
