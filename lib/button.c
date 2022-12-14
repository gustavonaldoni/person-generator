#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "string_type.h"
#include "utils.h"
#include "person.h"
#include "button.h"

void CreateButton(Button *button, int x, int y, int width, int height, String text, Font font)
{
    button->x = x;
    button->y = y;
    button->width = width;
    button->height = height;
    button->text = text;
    button->backgroundColor = DARKGRAY;
    button->textColor = RAYWHITE;
    button->fontSize = 20.0f;
    button->textSpacing = DEFAULT_FONT_SPACING;
    button->font = font;

    CalculateButtonTextPosition(button);
}

void DeleteButton(Button *button)
{
    stringDestroy(&button->text);
    free(button);
}

void CalculateButtonTextPosition(Button *button)
{
    float textWidth = 80.0f, textHeight = 20.0f;

    button->xText = button->x + ((button->width - (int)textWidth) / 2);
    button->yText = button->y + ((button->height - (int)textHeight) / 2);
}

void DrawButton(Button button)
{
    DrawButtonShadow(button);
    DrawRectangle(button.x, button.y, button.width, button.height, button.backgroundColor);
    DrawTextEx(button.font, button.text.content, (Vector2){button.xText, button.yText}, button.fontSize, button.textSpacing, button.textColor);
}

void DrawButtonShadow(Button button)
{
    const int shadowSpace = 10;
    Color shadowColor = BLACK;

    DrawRectangle(button.x + shadowSpace, button.y + shadowSpace, button.width, button.height, shadowColor);
}

void CreateRandomPeopleButtonMatrix(Button buttonMatrix[5][5], Person personMatrix[5][5])
{
    int i, j;
    int x, y;
    Font defaultFont;

    const int buttonSpace = 20, screenSpace = 60;
    const int buttonWidth = 200, buttonHeight = 80;

    x = screenSpace;
    y = 230;

    defaultFont = GetFontDefault();

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            CreateButton(&buttonMatrix[i][j], x, y, buttonWidth, buttonHeight, personMatrix[i][j].name, defaultFont);
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

int MouseIsInsideButtonsArea(Button topLeftButton, int buttonSpace)
{
    int x, y, totalWidth, totalHeight;
    Rectangle totalArea;

    x = topLeftButton.x;
    y = topLeftButton.y;

    totalWidth = 5 * topLeftButton.width + 4 * buttonSpace;
    totalHeight = 5 * topLeftButton.height + 4 * buttonSpace;

    totalArea = (Rectangle){x, y, totalWidth, totalHeight};

    return CheckCollisionPointRec(GetMousePosition(), totalArea);
}

void GetWhichButtonMouseIsOnTop(Button buttonMatrix[5][5], int *iButton, int *jButton)
{
    int i, j;
    Button testButton = {0};
    Rectangle buttonRectangle = {0};

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            testButton = buttonMatrix[i][j];
            buttonRectangle = (Rectangle){testButton.x, testButton.y, testButton.width, testButton.height};

            if (CheckCollisionPointRec(GetMousePosition(), buttonRectangle))
            {
                *iButton = i;
                *jButton = j;
            }
        }
    }
}

void ChangeButtonBackgroundColor(Button *button, Color newBackgroundColor)
{
    button->backgroundColor = newBackgroundColor;
}

void ChangeButtonTextColor(Button *button, Color newTextColor)
{
    button->textColor = newTextColor;
}

void ResetAllButtonsColors(Button buttonMatrix[5][5])
{
    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            ChangeButtonBackgroundColor(&buttonMatrix[i][j], DARKGRAY);
            ChangeButtonTextColor(&buttonMatrix[i][j], RAYWHITE);
        }
    }
}

void ResetAllButtonsColorsExceptOne(Button buttonMatrix[5][5], int iButton, int jButton)
{
    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i != iButton && j != jButton)
            {
                ChangeButtonBackgroundColor(&buttonMatrix[i][j], DARKGRAY);
                ChangeButtonTextColor(&buttonMatrix[i][j], RAYWHITE);
            }
        }
    }
}

int UserClickedOnButton(Button button)
{
    Rectangle buttonRectangle = {button.x, button.y, button.width, button.height};

    return CheckCollisionPointRec(GetMousePosition(), buttonRectangle) &&
           IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}