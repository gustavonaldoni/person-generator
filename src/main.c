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
#define MATRIX_SIZE 5

#define FILE_PATH "randomPeople.txt"

FILE *randomPeopleFile;

Person randomPeople[MAX_PEOPLE];
Person randomPeopleCopy[MAX_PEOPLE];

Person randomPeopleMatrix[MATRIX_SIZE][MATRIX_SIZE];
Button randomPeopleButtonMatrix[MATRIX_SIZE][MATRIX_SIZE];

int main(void)
{
    srand(time(NULL));

    CreateRandomPeople(randomPeople, MAX_PEOPLE);
    CreateRandomPeopleMatrix(randomPeopleMatrix, randomPeople);

    AppendPeopleToFile(randomPeople, randomPeopleFile, MAX_PEOPLE);
    GetPeopleFromFile(randomPeopleCopy, MAX_PEOPLE, FILE_PATH);

    CreateRandomPeopleButtonMatrix(randomPeopleButtonMatrix, randomPeopleMatrix);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Person generator");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        //printf("GetFontDefault().texture.id = %d", defaultFont.texture.id);

        DrawCenteredText("Random people generator!", GetScreenHeight() / 12, 50.0f, DARKGRAY);
        DrawCenteredText("Please click on one person to show it's information.", GetScreenHeight() / 12 * 2, 30.0f, DARKGRAY);

        DrawCenteredText("Created by Gustavo Azevedo Naldoni", GetScreenHeight() / 12 * 10.5, 20.0f, DARKGRAY);
        DrawCenteredText("December - 2022", GetScreenHeight() / 12 * 11, 20.0f, DARKGRAY);

        DrawRandomPeopleButtonMatrix(randomPeopleButtonMatrix);

        EndDrawing();
    }

    CloseWindow();

    DeleteFile(FILE_PATH);

    return 0;
}