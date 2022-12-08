#include <stddef.h>
#include <stdlib.h>
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

    String names[10] = {stringCreate("Joaquim"),
                        stringCreate("Josué"),
                        stringCreate("Jennifer"),
                        stringCreate("Maria"),
                        stringCreate("Beatriz"),
                        stringCreate("Sabrina"),
                        stringCreate("Rejane"),
                        stringCreate("Carlos"),
                        stringCreate("Gustavo"),
                        stringCreate("Adriano")};

    String jobs[10] = {stringCreate("nurse"),
                       stringCreate("doctor"),
                       stringCreate("lawyer"),
                       stringCreate("pilot"),
                       stringCreate("scientist"),
                       stringCreate("programmer"),
                       stringCreate("detective"),
                       stringCreate("writter"),
                       stringCreate("engineer"),
                       stringCreate("designer")};

    nameIndex = GenerateRandomInt(0, 9);
    jobIndex = GenerateRandomInt(0, 9);

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