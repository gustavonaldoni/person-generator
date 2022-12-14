#define DEFAULT_INFO_FONT_SIZE 30

typedef struct
{
    String name;
    int age, height;
    int numberOfChildren;
    String job;
} Person;

void CreatePerson(Person *, String, int, String, int, int);
void DeletePerson(Person *);
void CreateRandomPerson(Person *);
void CreateRandomPeopleMatrix(Person [5][5]);
void GetPersonInformationRectangle(Rectangle *);
void DrawPersonInformation(Person);