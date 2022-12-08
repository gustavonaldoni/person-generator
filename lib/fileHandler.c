#include <stdio.h>
#include "string_type.h"
#include "person.h"
#include "fileHandler.h"

void AppendPersonToFile(Person person, FILE *file)
{
    file = fopen("./randomPeople.txt", "a");
    fprintf(file, "%s,%d,%s;", person.name.content, person.age, person.job.content);
    fclose(file);
}

void AppendPeopleToFile(Person people[], FILE *file, int maxPeople)
{
    int i;

    for (i = 0; i < maxPeople; i++)
    {
        AppendPersonToFile(people[i], file);
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
    printf("totalLetters = %d, file content = %s ======\n", totalLetters, fileContent);

    fclose(file);
}