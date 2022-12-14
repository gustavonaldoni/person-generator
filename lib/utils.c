#include "raylib.h"
#include "utils.h"

void DrawCenteredText(const char *text, int y, float fontSize, Color color)
{
    int xText, yText;
    int textWidth;

    textWidth = MeasureTextEx(GetFontDefault(), text, fontSize, DEFAULT_FONT_SPACING).x;

    xText = (GetScreenWidth() - textWidth) / 2;
    yText = y;

    DrawTextEx(GetFontDefault(), text, (Vector2){xText, yText}, fontSize, DEFAULT_FONT_SPACING, color);
}

void DrawCross(int x, int y, int size, float thick, Color color)
{
    DrawLineEx((Vector2){x, y}, (Vector2){x + size, y + size}, thick, color);
    DrawLineEx((Vector2){x + size, y}, (Vector2){x, y + size}, thick, color);
}

void DrawSquareLines(int x, int y, int size, Color color)
{
    DrawRectangleLines(x, y, size, size, color);
}