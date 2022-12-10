#include <stdlib.h>
#include "raylib.h"
#include "string_type.h"
#include "utils.h"
#include "person.h"
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

    textWidth = MeasureTextEx(GetFontDefault(), button->text.content, button->fontSize, DEFAULT_FONT_SPACING).x;
    textHeight = MeasureTextEx(GetFontDefault(), button->text.content, button->fontSize, DEFAULT_FONT_SPACING).y;

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

void CreateRandomPeopleButtonMatrix(Button buttonMatrix[5][5], Person personMatrix[5][5])
{
    int i, j;
    int x, y;

    const int buttonSpace = 20, screenSpace = 60;
    const int buttonWidth = 200, buttonHeight = 80;

    x = screenSpace;
    y = 230;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            CreateButton(&buttonMatrix[i][j], x, y, buttonWidth, buttonHeight, personMatrix[i][j].name);
            x += buttonWidth + buttonSpace;
        }

        x = screenSpace;
        y += buttonHeight + buttonSpace;
    }
}

void DrawRandomPeopleButtonMatrix(Button buttonMatrix[5][5])
{
    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            DrawButton(buttonMatrix[i][j]);
        }
    }
}