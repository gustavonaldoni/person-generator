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

        EndDrawing();
    }

    CloseWindow();

    return 0;
}