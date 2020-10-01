/*Jarett Allie
September 1, 2020
Summary **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fileAmt = 0;

    //string of file name
    char *fileName[25];
    //amt of words
    int words[25];
    int chars[25];

    int max = 0;
    int min = 0;

    int wrdAmt;
    int charAmt;

    int counter = 0;

    for (int i = 0; i < argc; i++)
    {
        counter++;
    }

    if(counter == 2){
        printf("Most difficult document: %s\n", argv[1]);
        printf("Least difficult document: %s\n", argv[1]);
        return 0;
    }

    for (int i = 1; i < counter; i++)
    {
        charAmt = 0;
        wrdAmt = 0;

        fileAmt++;

        FILE *fileN;

        fileName[fileAmt - 1] = argv[i];

        fileN = fopen(fileName[fileAmt - 1], "r");

        char nextCh;

        nextCh = fgetc(fileN);

        while (nextCh != EOF)
        {
            if (nextCh == ' ' || nextCh == '\n')
            {
                wrdAmt++;
            }
            else
            {
                charAmt++;
            }
            nextCh = fgetc(fileN);
        }

        fclose(fileN);


        words[fileAmt - 1] = wrdAmt;
        chars[fileAmt - 1] = charAmt;
    }

    int i;
    float maxVal = (float) chars[0]/words[0];

    for (i = 1; i < argc - 1; i++)
    {
        if ((float) chars[i]/words[i] > maxVal)
        {
            maxVal = (float) chars[i]/words[i];
            max = i;
        }
    }

    int j;
    float minVal = (float) chars[0]/words[0];

    for (j = 1; j < argc-1; j++)
    {
        if ((float) chars[j]/words[j] < minVal)
        {
            minVal = (float) chars[j]/words[j];
            min = j;
        }
    }
    printf("Most difficult document: %s\n", fileName[max]);
    printf("Least difficult document: %s\n", fileName[min]);

    return 0;
}