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

void DrawPersonInformation(Person person)
{
    Rectangle rectangle = {0};
    GetPersonInformationRectangle(&rectangle);

    const int defaultSpace = 20;

    int crossSize, crossSpace;
    int xCross, yCross;

    int xSquare, ySquare;
    int squareSize;

    const char *personName;
    float personNameHeight;
    int yPersonName;

    const char *personAge;
    //float personAgeHeight;
    int yPersonAge;

    crossSize = 20;
    crossSpace = 5;

    xCross = rectangle.x + rectangle.width - crossSize - crossSpace;
    yCross = rectangle.y + crossSpace;

    xSquare = xCross - crossSpace;
    ySquare = yCross - crossSpace;
    squareSize = crossSize + 2 * crossSpace;

    DrawRectangleRec(rectangle, DARKGRAY);
    DrawSquareLines(xSquare, ySquare, squareSize, RED);
    DrawCross(xCross, yCross, crossSize, 1.3f, RED);

    personName = TextFormat("%s", person.name.content);
    personNameHeight = MeasureTextEx(GetFontDefault(), personName, DEFAULT_INFO_FONT_SIZE + 20, DEFAULT_FONT_SPACING).y;
    yPersonName = rectangle.y + personNameHeight + defaultSpace;

    personAge = TextFormat("Age: %d years", person.age);
    //personAgeHeight = MeasureTextEx(GetFontDefault(), personAge, DEFAULT_INFO_FONT_SIZE, DEFAULT_FONT_SPACING).y;
    yPersonAge = yPersonName + personNameHeight + defaultSpace;

    DrawCenteredText(personName, yPersonName, DEFAULT_INFO_FONT_SIZE + 20, RAYWHITE);
    DrawCenteredText(personAge, yPersonAge, DEFAULT_INFO_FONT_SIZE, RAYWHITE);
}