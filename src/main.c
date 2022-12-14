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

#define BUTTON_SPACE 20

FILE *randomPeopleFile;

Person randomPeople[MAX_PEOPLE];

Person randomPeopleMatrix[MATRIX_SIZE][MATRIX_SIZE];
Person randomPeopleMatrixFromFile[MATRIX_SIZE][MATRIX_SIZE];

Button randomPeopleButtonMatrix[MATRIX_SIZE][MATRIX_SIZE];

int displayPersonInformation = 0;

int main(void)
{
    Button topLeftButton = {0};
    int iButton = 0, jButton = 0;

    Button *selectedButton = NULL;
    Person *selectedPerson = NULL;

    Person *clickedPerson = NULL;

    Rectangle crossSquare = {0};

    srand(time(NULL));

    CreateRandomPeopleMatrix(randomPeopleMatrix);
    AppendPeopleToFile(randomPeopleMatrix, randomPeopleFile);

    GetPeopleFromFile(randomPeopleMatrixFromFile, MAX_PEOPLE, FILE_PATH);

    CreateRandomPeopleButtonMatrix(randomPeopleButtonMatrix, randomPeopleMatrixFromFile);
    topLeftButton = randomPeopleButtonMatrix[0][0];

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Person generator");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (MouseIsInsideButtonsArea(topLeftButton, BUTTON_SPACE) &&
            displayPersonInformation == 0)
        {
            GetWhichButtonMouseIsOnTop(randomPeopleButtonMatrix, &iButton, &jButton);

            selectedButton = &randomPeopleButtonMatrix[iButton][jButton];
            selectedPerson = &randomPeopleMatrix[iButton][jButton];

            ChangeButtonBackgroundColor(selectedButton, YELLOW);
            ChangeButtonTextColor(selectedButton, BLACK);

            ResetAllButtonsColorsExceptOne(randomPeopleButtonMatrix, iButton, jButton);

            if (UserClickedOnButton(*selectedButton))
            {
                clickedPerson = selectedPerson;
                displayPersonInformation = 1;
            }
        }

        else
            ResetAllButtonsColors(randomPeopleButtonMatrix);

        DrawCenteredText("Random people generator!", GetScreenHeight() / 12, 50.0f, DARKGRAY);
        DrawCenteredText("Please click on one person to show it's information.", GetScreenHeight() / 12 * 2, 30.0f, DARKGRAY);

        DrawCenteredText("Created by Gustavo Azevedo Naldoni", GetScreenHeight() / 12 * 10.5, 20.0f, DARKGRAY);
        DrawCenteredText("December - 2022", GetScreenHeight() / 12 * 11, 20.0f, DARKGRAY);

        if (displayPersonInformation == 1)
        {
            DrawPersonInformation(*clickedPerson, &crossSquare);

            if (UserClickedOnCrossSquare(crossSquare))
                displayPersonInformation = 0;
        }
        else
            DrawRandomPeopleButtonMatrix(randomPeopleButtonMatrix);

        EndDrawing();
    }

    CloseWindow();

    DeleteFile(FILE_PATH);

    return 0;
}