#include "person.h"
#include "random.h"

void CreatePerson(Person *person, String name, int age, float height, String job)
{
    person->name = name;
    person->age = age;
    person->height = height;
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
    int i, nameIndex, jobIndex;

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
    person->height = GenerateRandomFloat(1.5f, 2.0f, 2);
    person->job = jobs[jobIndex];

    for (i = 0; i < 10; i++)
    {
        stringDestroy(&names[i]);
        stringDestroy(&jobs[i]);
    }
}