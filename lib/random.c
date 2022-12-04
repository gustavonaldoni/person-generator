#include "random.h"

int GenerateRandomInt(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

float GenerateRandomFloat(float lower, float upper, int decimalCases)
{
    int decimal, randInt;
    float result;

    int i, n;
    char s[decimalCases];

    result = 0.0f;

    lower = lower * 10;
    upper = upper * 10;

    for (i = 0; i < decimalCases; i++)
    {
        s[i] = '9';
    }

    n = atoi(s);

    decimal = GenerateRandomInt(0, n);
    randInt = GenerateRandomInt(lower, upper);

    result = (randInt / 10) + (float)(decimal / powf(10, decimalCases));

    return result;
}