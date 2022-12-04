#include "raylib.h"

#define SCREEN_WIDTH 4 * 300
#define SCREEN_HEIGHT 3 * 300

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Person generator");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}