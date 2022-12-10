typedef struct
{
    int x, y;
    int width, height;
    String text;
    float fontSize, textSpacing;
    int xText, yText;
    Color backgroundColor, textColor;
} Button;

void CreateButton(Button *, int, int, int, int, String);
void DeleteButton(Button *);
void DrawButton(Button);
void CreateRandomPeopleButtonMatrix(Button [5][5], Person [5][5]);
void DrawRandomPeopleButtonMatrix(Button [5][5]);