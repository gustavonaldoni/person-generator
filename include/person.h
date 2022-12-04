#include "string_type.h"

typedef struct
{
    String name;
    int age;
    float height;
    String job;
} Person;

void CreatePerson(Person *, String, int, float, String);
void DeletePerson(Person *);
void CreateRandomPerson(Person *);