#include "string_type.h"

String stringCreate(char *string)
{
    String result;
    size_t length, i;
    char *content;

    result.content = NULL;
    content = NULL;

    length = strlen(string);
    content = (char *)malloc(length + 1);

    if (content == NULL)
        return result;

    for (i = 0; i < length; i++)
    {
        content[i] = string[i];
    }

    content[length] = '\0';

    result.content = content;

    return result;
}

int stringDestroy(String *string)
{
    char *aux;

    aux = string->content;

    if (aux == NULL)
        return 0;

    free(aux);
    aux = NULL;
    return 1;
}

size_t stringLength(String string)
{
    size_t i;

    i = 0;

    while (string.content[i] != '\0')
    {
        i++;
    }

    return i;
}

char stringCharAt(String string, unsigned int index)
{
    size_t lengthString;

    lengthString = stringLength(string);

    if (index > lengthString - 1)
        return -1;

    return string.content[index];
}

String stringConcat(String source, String destination)
{
    size_t lengthSource, lengthDestination, lengthResult, i;
    String resultString;
    char *resultContent;

    resultString.content = NULL;
    resultContent = NULL;

    lengthSource = stringLength(source);
    lengthDestination = stringLength(destination);
    lengthResult = lengthSource + lengthDestination;

    resultContent = (char *)malloc(lengthResult + 1);

    if (resultContent == NULL)
        return resultString;

    for (i = 0; i < lengthResult; i++)
    {
        if (i < lengthDestination)
            resultContent[i] = destination.content[i];

        else
            resultContent[i] = source.content[i - lengthDestination];
    }

    resultContent[lengthResult] = '\0';

    resultString = stringCreate(resultContent);

    free(resultContent);

    return resultString;
}

String stringToLower(String original)
{
    size_t lengthOriginal, i;
    String resultString;
    char *resultContent;

    resultString.content = NULL;
    resultContent = NULL;

    lengthOriginal = stringLength(original);

    resultContent = (char *)malloc(lengthOriginal + 1);

    if (resultContent == NULL)
        return resultString;

    for (i = 0; i < lengthOriginal; i++)
    {
        resultContent[i] = tolower(original.content[i]);
    }

    resultContent[lengthOriginal] = '\0';
    resultString = stringCreate(resultContent);

    free(resultContent);

    return resultString;
}

String stringToUpper(String original)
{
    size_t lengthOriginal, i;
    String resultString;
    char *resultContent;

    resultString.content = NULL;
    resultContent = NULL;

    lengthOriginal = stringLength(original);

    resultContent = (char *)malloc(lengthOriginal + 1);

    if (resultContent == NULL)
        return resultString;

    for (i = 0; i < lengthOriginal; i++)
    {
        resultContent[i] = toupper(original.content[i]);
    }

    resultContent[lengthOriginal] = '\0';
    resultString = stringCreate(resultContent);

    free(resultContent);

    return resultString;
}

String stringCut(String string, int firstIndex, int lastIndex)
{
    size_t lengthResult, lengthString;
    String resultString;
    char *resultContent;
    unsigned int i, j;

    resultString.content = NULL;
    resultContent = NULL;

    lengthString = stringLength(string);

    if (firstIndex < 0 || firstIndex > lastIndex)
        return resultString;

    if (lastIndex > lengthString - 1)
        return resultString;

    lengthResult = (size_t)lastIndex - (size_t)firstIndex + 1;

    resultContent = (char *)malloc(lengthResult + 1);

    i = 0;
    for (j = firstIndex; j <= lastIndex; j++)
    {
        resultContent[i] = string.content[j];
        i++;
    }

    resultContent[lengthResult] = '\0';
    resultString = stringCreate(resultContent);

    free(resultContent);

    return resultString;
}

String stringTrim(String original)
{
    size_t lengthOriginal, firstIndex, lastIndex, i;

    lengthOriginal = stringLength(original);

    firstIndex = 0;
    lastIndex = lengthOriginal - 1;

    // Finding firstIndex
    for (i = 0; i < lengthOriginal; i++)
    {
        if (original.content[i] != ' ')
        {
            firstIndex = i;
            break;
        }
    }

    // Finding lastIndex
    for (i = lengthOriginal - 1; i >= 0; i--)
    {
        if (original.content[i] != ' ')
        {
            lastIndex = i;
            break;
        }
    }

    return stringCut(original, (int)firstIndex, (int)lastIndex);
}

int stringContains(String original, String substring)
{
    size_t lengthOriginal, lengthSubstring, i, j;
    unsigned int counter;
    int firstIndex;

    lengthOriginal = stringLength(original);
    lengthSubstring = stringLength(substring);

    j = 0;
    counter = 0;

    firstIndex = -1;

    for (i = 0; i < lengthOriginal; i++)
    {
        if (original.content[i] == substring.content[0])
        {
            counter += 1;
            firstIndex = i;

            for (j = 1; j < lengthSubstring; j++)
            {
                if (original.content[i + j] == substring.content[j])
                    counter += 1;

                else
                {
                    counter = 0;
                    firstIndex = -1;
                    break;
                }
            }
        }

        if (counter == lengthSubstring)
            return firstIndex;
    }

    return firstIndex;
}

String stringReplace(String original, String toReplace, String replaceBy)
{
    size_t lengthOriginal, lengthToReplace, lengthReplaceBy, lengthResult, i, j, d;
    String resultString;
    char *resultContent;
    int firstLetterIndex, lastLetterIndex;

    resultString.content = NULL;
    resultContent = NULL;

    firstLetterIndex = -1;
    lastLetterIndex = -1;

    lengthToReplace = stringLength(toReplace);
    lengthOriginal = stringLength(original);
    lengthReplaceBy = stringLength(replaceBy);

    lengthResult = 0;

    j = 0;

    firstLetterIndex = stringContains(original, toReplace);

    j = 0;

    if (firstLetterIndex != -1)
    {
        lastLetterIndex = firstLetterIndex + lengthToReplace - 1;

        if (lengthReplaceBy == lengthToReplace)
        {
            lengthResult = lengthOriginal;

            resultContent = (char *)malloc(lengthResult + 1);

            if (resultContent == NULL)
                return resultString;

            for (i = 0; i < lengthResult; i++)
            {
                if (i >= firstLetterIndex && i <= lastLetterIndex)
                {
                    resultContent[i] = replaceBy.content[j];
                    j += 1;
                }

                else
                    resultContent[i] = original.content[i];
            }
        }

        if (lengthReplaceBy > lengthToReplace)
        {
            d = lengthReplaceBy - lengthToReplace;
            lengthResult = lengthOriginal + d;

            resultContent = (char *)malloc(lengthResult + 1);

            for (i = 0; i < lengthResult; i++)
            {
                if (i >= firstLetterIndex && i <= lastLetterIndex + d)
                {
                    resultContent[i] = replaceBy.content[j];
                    j += 1;
                }

                else
                {
                    if (i > lastLetterIndex)
                        resultContent[i] = original.content[i - d];

                    else if (i < firstLetterIndex)
                        resultContent[i] = original.content[i];
                }
            }
        }

        if (lengthReplaceBy < lengthToReplace)
        {
            d = lengthToReplace - lengthReplaceBy;
            lengthResult = lengthOriginal - d;

            resultContent = (char *)malloc(lengthResult + 1);

            for (i = 0; i < lengthResult; i++)
            {
                if (i >= firstLetterIndex && i <= lastLetterIndex - d)
                {
                    resultContent[i] = replaceBy.content[j];
                    j += 1;
                }

                else
                {
                    if (i < firstLetterIndex)
                        resultContent[i] = original.content[i];

                    else
                        resultContent[i] = original.content[i + d];
                }
            }
        }

        resultContent[lengthResult] = '\0';
        resultString = stringCreate(resultContent);

        free(resultContent);
    }

    return resultString;
}

int stringStartsWith(String original, String substring)
{
    size_t lengthOriginal, lengthSubstring, i;

    lengthOriginal = stringLength(original);
    lengthSubstring = stringLength(substring);

    if (lengthSubstring > lengthOriginal)
        return 0;

    if (lengthSubstring == 0 || lengthOriginal == 0)
        return 0;

    for (i = 0; i < lengthSubstring; i++)
    {
        if (original.content[i] != substring.content[i])
            return 0;
    }

    return 1;
}

int stringEndsWith(String original, String substring)
{
    size_t lengthOriginal, lengthSubstring;
    int i, j;

    lengthOriginal = stringLength(original);
    lengthSubstring = stringLength(substring);

    if (lengthSubstring > lengthOriginal)
        return 0;

    if (lengthSubstring == 0 || lengthOriginal == 0)
        return 0;

    j = lengthOriginal - 1;

    for (i = lengthSubstring - 1; i >= 0; i--)
    {
        if (original.content[j] != substring.content[i])
            return 0;

        j--;
    }

    return 1;
}

int stringAreEqual(String string1, String string2)
{
    size_t lengthString1, lengthString2, i;

    lengthString1 = stringLength(string1);
    lengthString2 = stringLength(string2);

    if (lengthString1 != lengthString2)
        return 0;

    for (i = 0; i < lengthString1; i++)
    {
        if (string1.content[i] != string2.content[i])
            return 0;
    }

    return 1;
}

String stringCopy(String string)
{
    return stringCreate(string.content);
}

int stringCounts(String original, String substring)
{
    size_t lengthOriginal, lengthSubstring, i, j;
    unsigned int counter, counterResult;

    lengthOriginal = stringLength(original);
    lengthSubstring = stringLength(substring);

    j = 0;
    counter = 0;
    counterResult = 0;

    if (lengthOriginal == 0 || lengthSubstring == 0)
        return 0;

    for (i = 0; i < lengthOriginal; i++)
    {
        if (original.content[i] == substring.content[0])
        {
            counter += 1;

            for (j = 1; j < lengthSubstring; j++)
            {
                if (original.content[i + j] == substring.content[j])
                    counter += 1;

                else
                {
                    counter = 0;
                    break;
                }
            }
        }

        if (counter == lengthSubstring)
        {
            counter = 0;
            counterResult += 1;
        }
    }

    return counterResult;
}

String stringReverse(String string)
{
    size_t lengthString, i, j;
    String resultString;
    char *resultContent;

    resultString.content = NULL;
    resultContent = NULL;

    lengthString = stringLength(string);

    if (lengthString == 0)
    {
        resultString = stringCreateEmpty();
        return resultString;
    }

    resultContent = (char *)malloc(lengthString + 1);

    j = lengthString - 1;
    for (i = 0; i < lengthString; i++)
    {
        resultContent[i] = string.content[j];
        j--;
    }

    resultContent[lengthString] = '\0';
    resultString = stringCreate(resultContent);

    free(resultContent);

    return resultString;
}

int stringFirstIndexOf(String string, char character)
{
    size_t lengthString, i;
    int resultIndex;

    lengthString = stringLength(string);
    resultIndex = -1;

    for (i = 0; i < lengthString; i++)
    {
        if (string.content[i] == character)
        {
            resultIndex = (int)i;
            return resultIndex;
        }
    }

    return resultIndex;
}

int stringCutIndexOf(String string, char character, int startIndex, int endIndex)
{
    size_t lengthString, i;
    int resultIndex;

    lengthString = stringLength(string);
    resultIndex = -1;

    if (startIndex >= lengthString || startIndex > endIndex)
        return resultIndex;

    if (endIndex >= lengthString || endIndex < startIndex)
        return resultIndex;

    for (i = startIndex; i < endIndex + 1; i++)
    {
        if (string.content[i] == character)
        {
            resultIndex = (int)i;
            return resultIndex;
        }
    }

    return resultIndex;
}

int stringLastIndexOf(String string, char character)
{
    size_t lengthString, i;
    int resultIndex;

    lengthString = stringLength(string);
    resultIndex = -1;

    for (i = 0; i < lengthString; i++)
    {
        if (string.content[i] == character)
            resultIndex = (int)i;
    }

    return resultIndex;
}

String stringCreateEmpty()
{
    return stringCreate("");
}

int stringIsEmpty(String string)
{
    String emptyString = stringCreateEmpty();
    int result = stringAreEqual(string, emptyString);

    stringDestroy(&emptyString);

    return result;
}

String *stringSplit(String string, char *separator, int *resultArraySize)
{
    String copy;
    unsigned int counter;
    char *token;
    String *result;
    int i;

    copy.content = NULL;
    counter = 0;
    token = NULL;
    result = NULL;

    copy = stringCopy(string);

    token = strtok(string.content, separator);
    while (token != NULL)
    {
        counter++;
        token = strtok(NULL, separator);
    }

    token = NULL;
    result = (String *) malloc(counter * sizeof(String));

    if (result == NULL)
        return NULL;

    token = strtok(copy.content, separator);

    i = 0;
    while (token != NULL)
    {
        result[i] = stringCreate(token);
        token = strtok(NULL, separator);
        i++;
    }

    *resultArraySize = counter;
    return result;
}