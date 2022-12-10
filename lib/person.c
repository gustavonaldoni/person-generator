#include <stddef.h>
#include <stdlib.h>
#include "raylib.h"
#include "string_type.h"
#include "random.h"
#include "person.h"

void CreatePerson(Person *person, String name, int age, String job)
{
    person->name = name;
    person->age = age;
    person->job = job;
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
}

void CreateRandomPeople(Person people[], int maxPeople)
{
    int i;

    for (i = 0; i < maxPeople; i++)
    {
        CreateRandomPerson(&people[i]);
    }
}

void CreateRandomPeopleMatrix(Person peopleMatrix[5][5], Person peopleArray[])
{
    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            peopleMatrix[i][j] = peopleArray[5*i + j];
        }
    }
}
