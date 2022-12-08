#include <stdio.h>
#include "raylib.h"
#include "string_type.h"
#include "person.h"
#include "fileHandler.h"

#define SCREEN_WIDTH 4 * 300
#define SCREEN_HEIGHT 3 * 300
#define MAX_PEOPLE 20

#define FILE_PATH "randomPeople.txt"

FILE *randomPeopleFile;
Person randomPeople[MAX_PEOPLE];
Person randomPeopleCopy[MAX_PEOPLE];

int main(void)
{
    CreateRandomPeople(randomPeople, MAX_PEOPLE);
    AppendPeopleToFile(randomPeople, randomPeopleFile, MAX_PEOPLE);

    GetPeopleFromFile(randomPeopleCopy, MAX_PEOPLE, FILE_PATH);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Person generator");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    DeleteFile(FILE_PATH);

    return 0;
}