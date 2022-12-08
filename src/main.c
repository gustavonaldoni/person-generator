#include <stdio.h>
#include "raylib.h"
#include "string_type.h"
#include "person.h"
#include "fileHandler.h"

#define SCREEN_WIDTH 4 * 300
#define SCREEN_HEIGHT 3 * 300
#define MAX_PEOPLE 20

FILE *randomPeopleFile;
Person randomPeople[MAX_PEOPLE];

int main(void)
{
    CreateRandomPeople(randomPeople, MAX_PEOPLE);
    AppendPeopleToFile(randomPeople, randomPeopleFile, MAX_PEOPLE);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Person generator");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    DeleteFile("randomPeople.txt");

    return 0;
}