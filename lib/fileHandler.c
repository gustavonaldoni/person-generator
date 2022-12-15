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

void GetPeopleFromFile(Person peopleMatrix[5][5], int maxPeople, char *fileName)
{
    FILE *file;
    int totalLetters = 0;

    int i, j;
    String peopleInfo;
    String *peopleInfoArray = NULL;
    int peopleInfoArrayLength = 0;

    String *personInfoArray = NULL;
    int personInfoArraySize = 0;
    Person person = {0};

    file = fopen(fileName, "r");

    fseek(file, 0, SEEK_END);
    totalLetters = (int)ftell(file);

    char fileContent[totalLetters];

    fseek(file, 0, SEEK_SET);
    fgets(fileContent, totalLetters + 1, file);

    peopleInfo = stringCreate(&fileContent[0]);
    peopleInfoArray = stringSplit(peopleInfo, ";", &peopleInfoArrayLength);

    Person personArray[peopleInfoArrayLength];

    for (i = 0; i < peopleInfoArrayLength; i++)
    {
        personInfoArray = stringSplit(peopleInfoArray[i], ",", &personInfoArraySize);

        for (j = 0; j < personInfoArraySize; j++)
        {
            person.name = personInfoArray[0];
            person.age = atoi(personInfoArray[1].content);
            person.job = personInfoArray[2];
            person.height = atoi(personInfoArray[3].content);
            person.numberOfChildren = atoi(personInfoArray[4].content);

            personArray[i] = person;
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            peopleMatrix[i][j] = personArray[5*i + j];
        }
    }

    fclose(file);
}