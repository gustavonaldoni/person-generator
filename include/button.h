typedef struct
{
    int x, y;
    int width, height;
    String text;
    float fontSize, textSpacing;
    int xText, yText;
    Color backgroundColor, textColor;
    Font font;
} Button;

void CreateButton(Button *, int, int, int, int, String, Font);
void DeleteButton(Button *);
void CalculateButtonTextPosition(Button *);
void DrawButton(Button);
void DrawButtonShadow(Button);
void CreateRandomPeopleButtonMatrix(Button [5][5], Person [5][5]);
void DrawRandomPeopleButtonMatrix(Button [5][5]);