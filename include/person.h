#include "string_type.h"

typedef struct
{
    String name;
    int age;
    String job;
} Person;

void CreatePerson(Person *, String, int, String);
void DeletePerson(Person *);
void CreateRandomPerson(Person *);
void CreateRandomPeople(Person *, int);