#include <stdio.h>
#include "raylib.h"
#include "string_type.h"
#include "person.h"
#include "fileHandler.h"

void AppendPersonToFile(Person person, FILE *file)
{
    file = fopen("./randomPeople.txt", "a");
    fprintf(file, "%s,%d,%s,%d,%d;", person.name.content, person.age, person.job.content, person.height, person.numberOfChildren);
    fclose(file);
}

void AppendPeopleToFile(Person peopleMatrix[5][5], FILE *file)
{
    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            AppendPersonToFile(peopleMatrix[i][j], file);
        }
    }
}

void DeleteFile(char *fileName)
{
    remove(fileName);
}

void GetPeopleFromFile(Person people[], int maxPeople, char *fileName)
{
    FILE *file;
    int totalLetters = 0;

    file = fopen(fileName, "r");

    fseek(file, 0, SEEK_END);
    totalLetters = (int)ftell(file);

    char fileContent[totalLetters];

    fseek(file, 0, SEEK_SET);
    fgets(fileContent, totalLetters + 1, file);

    fclose(file);
}