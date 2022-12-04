#include "fileHandler.h"

void AppendPersonToFile(Person person, FILE *file)
{
    file = fopen("randomPeople.txt", "a");
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