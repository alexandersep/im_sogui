#ifndef IMSOGUI
#define IMSOGUI

#include "raylib.h"

//typedef struct {
//    int owner; // when went to draw use the pointer to that function (like menu group)
//    int item; // 
//    int index; // in case array
//} IMSOGUI_id;

typedef struct {
    int item;
} IMSOGUI_id;

typedef struct {
    IMSOGUI_id hot;
    IMSOGUI_id active;
} IMSOGUI_context;

bool imsogui_isinside(Rectangle box);
bool imsogui_dobutton(IMSOGUI_context *ui, IMSOGUI_id id, Rectangle rect);

#endif // IMSOGUI
