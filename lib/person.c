#include <stddef.h>
#include <stdlib.h>
#include "raylib.h"
#include "string_type.h"
#include "random.h"
#include "utils.h"
#include "person.h"

void CreatePerson(Person *person, String name, int age, String job, int height, int numberOfChildren)
{
    person->name = name;
    person->age = age;
    person->job = job;
    person->height = height;
    person->numberOfChildren = numberOfChildren;
}

void DeletePerson(Person *person)
{
    stringDestroy(&(person->name));
    stringDestroy(&(person->job));

    free(person);
}

void CreateRandomPerson(Person *person)
{
    int nameIndex, jobIndex;

    String names[20] = {stringCreate("Joaquim"),
                        stringCreate("Josué"),
                        stringCreate("Jennifer"),
                        stringCreate("Maria"),
                        stringCreate("Beatriz"),
                        stringCreate("Sabrina"),
                        stringCreate("Rejane"),
                        stringCreate("Carlos"),
                        stringCreate("Gustavo"),
                        stringCreate("Adriano"),
                        stringCreate("Rafael"),
                        stringCreate("André"),
                        stringCreate("Homer"),
                        stringCreate("Bart"),
                        stringCreate("Ariana"),
                        stringCreate("Javier"),
                        stringCreate("Maycon"),
                        stringCreate("Juliana"),
                        stringCreate("Luisa"),
                        stringCreate("Takeshi")};

    String jobs[20] = {stringCreate("nurse"),
                       stringCreate("doctor"),
                       stringCreate("lawyer"),
                       stringCreate("pilot"),
                       stringCreate("scientist"),
                       stringCreate("programmer"),
                       stringCreate("detective"),
                       stringCreate("writter"),
                       stringCreate("engineer"),
                       stringCreate("designer"),
                       stringCreate("firefighter"),
                       stringCreate("police officer"),
                       stringCreate("teacher"),
                       stringCreate("politician"),
                       stringCreate("biologist"),
                       stringCreate("model"),
                       stringCreate("painter"),
                       stringCreate("salesman"),
                       stringCreate("travel agent"),
                       stringCreate("dancer")};

    nameIndex = GenerateRandomInt(0, 19);
    jobIndex = GenerateRandomInt(0, 19);

    person->name = names[nameIndex];
    person->age = GenerateRandomInt(18, 70);
    person->job = jobs[jobIndex];
    person->height = GenerateRandomInt(150, 200);
    person->numberOfChildren = GenerateRandomInt(0, 4);
}

void CreateRandomPeopleMatrix(Person peopleMatrix[5][5])
{
    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            CreateRandomPerson(&peopleMatrix[i][j]);
        }
    }
}

void GetPersonInformationRectangle(Rectangle *rectangle)
{
    rectangle->width = 0.6f * (float)GetScreenWidth();
    rectangle->height = 0.6f * (float)GetScreenHeight();
    rectangle->x = (GetScreenWidth() - rectangle->width) / 2;
    rectangle->y = (GetScreenHeight() - rectangle->height) / 2 + 30;
}

void DrawPersonInformation(Person person, Rectangle *crossSquare)
{
    Rectangle rectangle = {0};
    GetPersonInformationRectangle(&rectangle);
    const int rectangleBorderSpace = 5;

    const int defaultSpace = 20;

    int crossSize, crossSpace;
    int xCross, yCross;

    int xSquare, ySquare;
    int squareSize;

    const char *personName = NULL;
    float personNameHeight;
    int yPersonName;

    const char *personAgeAndHeight = NULL;
    float personAgeAndHeightHeight;
    int yPersonAgeAndHeight;

    const char *personJob = NULL;
    float personJobHeight;
    int yPersonJob;

    const char *personNumberOfChildren = NULL;
    //float personNumberOfChildrenHeight;
    int yPersonNumberOfChildren;

    const char *quitInformation = NULL;
    float quitInformationHeight;
    int yQuitInformation;

    crossSize = 20;
    crossSpace = 5;

    xSquare = rectangle.x + rectangle.width - crossSize - 2 * crossSpace - rectangleBorderSpace;
    ySquare = rectangle.y + rectangleBorderSpace;
    squareSize = crossSize + 2 * crossSpace;

    *crossSquare = (Rectangle){xSquare, ySquare, squareSize, squareSize};

    xCross = xSquare + rectangleBorderSpace;
    yCross = ySquare + rectangleBorderSpace;

    DrawRectangleRec(rectangle, DARKGRAY);
    DrawSquareLines(xSquare, ySquare, squareSize, YELLOW);
    DrawCross(xCross, yCross, crossSize, 1.5f, YELLOW);

    personName = person.name.content;
    personNameHeight = MeasureTextEx(GetFontDefault(), personName, DEFAULT_INFO_FONT_SIZE + 20, DEFAULT_FONT_SPACING).y;
    yPersonName = rectangle.y + personNameHeight + 2 * defaultSpace;

    personAgeAndHeight = TextFormat("%d years - %d cm", person.age, person.height);
    personAgeAndHeightHeight = MeasureTextEx(GetFontDefault(), personAgeAndHeight, DEFAULT_INFO_FONT_SIZE, DEFAULT_FONT_SPACING).y;
    yPersonAgeAndHeight = yPersonName + personNameHeight + defaultSpace;

    personJob = TextFormat("%s", person.job.content);
    personJobHeight = MeasureTextEx(GetFontDefault(), personJob, DEFAULT_INFO_FONT_SIZE, DEFAULT_FONT_SPACING).y;
    yPersonJob = yPersonAgeAndHeight + personAgeAndHeightHeight + defaultSpace;

    personNumberOfChildren = TextFormat("%d children", person.numberOfChildren);
    //personNumberOfChildrenHeight = MeasureTextEx(GetFontDefault(), personNumberOfChildren, DEFAULT_INFO_FONT_SIZE, DEFAULT_FONT_SPACING).y;
    yPersonNumberOfChildren = yPersonJob + personJobHeight + defaultSpace;

    quitInformation = TextFormat("Left click the yellow cross to return.");
    quitInformationHeight = MeasureTextEx(GetFontDefault(), quitInformation, DEFAULT_INFO_FONT_SIZE / 2, DEFAULT_FONT_SPACING).y;
    yQuitInformation = rectangle.y + rectangle.height - quitInformationHeight - 4 * defaultSpace;

    DrawCenteredText(personName, yPersonName, DEFAULT_INFO_FONT_SIZE + 20, RAYWHITE);
    DrawCenteredText(personAgeAndHeight, yPersonAgeAndHeight, DEFAULT_INFO_FONT_SIZE, RAYWHITE);
    DrawCenteredText(personJob, yPersonJob, DEFAULT_INFO_FONT_SIZE, RAYWHITE);
    DrawCenteredText(personNumberOfChildren, yPersonNumberOfChildren, DEFAULT_INFO_FONT_SIZE, RAYWHITE);
    DrawCenteredText(quitInformation, yQuitInformation, (float)DEFAULT_INFO_FONT_SIZE / 1.5f, YELLOW);
}

int UserClickedOnCrossSquare(Rectangle crossSquare)
{
    return CheckCollisionPointRec(GetMousePosition(), crossSquare) &&
           IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}