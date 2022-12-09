#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "string_type.h"
#include "utils.h"
#include "person.h"
#include "fileHandler.h"
#include "button.h"

#define SCREEN_WIDTH 4 * 300
#define SCREEN_HEIGHT 3 * 300
#define MAX_PEOPLE 25

#define FILE_PATH "randomPeople.txt"

FILE *randomPeopleFile;
Person randomPeople[MAX_PEOPLE];
Person randomPeopleCopy[MAX_PEOPLE];

int main(void)
{
    srand(time(NULL));

    CreateRandomPeople(randomPeople, MAX_PEOPLE);
    AppendPeopleToFile(randomPeople, randomPeopleFile, MAX_PEOPLE);

    GetPeopleFromFile(randomPeopleCopy, MAX_PEOPLE, FILE_PATH);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Person generator");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCenteredText("Random people generator!", GetScreenHeight() / 12, 50.0f, DARKGRAY);
        DrawCenteredText("Please click on one person to show it's information.", GetScreenHeight() / 12 * 2, 30.0f, DARKGRAY);

        DrawCenteredText("Created by Gustavo Azevedo Naldoni", GetScreenHeight() / 12 * 11, 20.0f, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();

    DeleteFile(FILE_PATH);

    return 0;
}