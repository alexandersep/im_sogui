#include "imsogui.h"

static bool imsogui_isactive(IMSOGUI_context *ui, IMSOGUI_id id) {
    if (ui->active.item == id.item) {
        return true;
    }
    return false;
}

static bool imsogui_ishot(IMSOGUI_context *ui, IMSOGUI_id id) {
    if (ui->hot.item == id.item) {
        return true;
    }
    return false;
}

bool imsogui_isinside(Rectangle rect) {
    Vector2 position = GetMousePosition(); // If mouse is not on screen (0,0)
    return (position.x >= rect.x && position.x <= rect.x + rect.width && 
            position.y >= rect.y && position.y <= rect.y + rect.height);
}

bool imsogui_dobutton(IMSOGUI_context *ui, IMSOGUI_id id, Rectangle rect) {
    bool result = false;
    if (imsogui_isactive(ui, id)) {
        if (IsMouseButtonUp(MOUSE_LEFT_BUTTON)) {
            if (imsogui_ishot(ui, id)) {
                result = true;
            }
            ui->active.item = -1;
        }
    } else if (imsogui_ishot(ui, id)) {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            ui->active.item = id.item;
        }
    }

    if (imsogui_isinside(rect)) {
        ui->hot.item = id.item;
    } else if (ui->hot.item == id.item) {
        ui->hot.item = -1;
    }

    if (imsogui_ishot(ui, id)) {
        DrawRectangleRec(rect, RED);
    } else if (imsogui_isactive(ui, id)) {
        DrawRectangleRec(rect, GREEN);
    } else {
        DrawRectangleRec(rect, GRAY);
    }

    return result;
}
