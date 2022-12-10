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
void CreateRandomPeopleMatrix(Person [5][5], Person *);