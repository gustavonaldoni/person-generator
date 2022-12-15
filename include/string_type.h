#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    char *content;
} String;

String stringCreate(char *);
int stringDestroy(String *);
size_t stringLength(String);
char stringCharAt(String, unsigned int);
String stringConcat(String, String);
String stringToLower(String);
String stringToUpper(String);
String stringCut(String, int, int);
String stringTrim(String);
int stringContains(String, String);
String stringReplace(String, String, String);
int stringStartsWith(String, String);
int stringEndsWith(String, String);
int stringAreEqual(String, String);
String stringCopy(String);
int stringCounts(String, String);
String stringReverse(String);
int stringFirstIndexOf(String, char);
int stringLastIndexOf(String, char);
int stringCutIndexOf(String, char, int, int);
String stringCreateEmpty();
int stringIsEmpty(String);
String *stringSplit(String, char *, int *);