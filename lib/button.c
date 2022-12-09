#include <stdlib.h>
#include "raylib.h"
#include "string_type.h"
#include "utils.h"
#include "button.h"

void CreateButton(Button *button, int x, int y, int width, int height, String text)
{
    int textWidth, textHeight;

    button->x = x;
    button->y = y;
    button->width = width;
    button->height = height;
    button->text = text;
    button->backgroundColor = DARKGRAY;
    button->textColor = RAYWHITE;
    button->fontSize = 20.0f;
    button->textSpacing = DEFAULT_FONT_SPACING;

    textWidth = MeasureTextEx(GetFontDefault(), button->text.content, button->fontSize, 1.0f).x;
    textHeight = MeasureTextEx(GetFontDefault(), button->text.content, button->fontSize, 1.0f).y;

    button->xText = button->x + (button->width - textWidth) / 2;
    button->yText = button->y + (button->height - textHeight) / 2;
}

void DeleteButton(Button *button)
{
    stringDestroy(&button->text);
    free(button);
}

void DrawButton(Button button)
{
    DrawRectangle(button.x, button.y, button.width, button.height, button.backgroundColor);
    DrawTextEx(GetFontDefault(), button.text.content, (Vector2){button.xText, button.yText}, button.fontSize, button.textSpacing, button.textColor);
}