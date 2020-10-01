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
    char *fileName[10];
        //amt of words
    int words[10];

    int max = 0;
    int min = 0;
    int wrdAmt;

    int counter = 0;
    for (int i = 0; i < argc; i++)
    {
        counter++;
    }

    if(counter == 2){
        printf("Most difficult document: %s", argv[1]);
        printf("\n");
        printf("Least difficult document: %s", argv[1]);
        return 0;
    }

    for (int i = 1; i < counter; i++)
    {
        wrdAmt = 0;
        fileAmt++;

        FILE *fileN;

        fileName[fileAmt - 1] = (char *)malloc(20);
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
            nextCh = fgetc(fileN);
        }

        fclose(fileN);

        words[fileAmt - 1] = wrdAmt;
    }

    int i;
    int maxVal = words[0];
    for (i = 1; i < argc; i++)
        if (words[i] > maxVal)
        {
            maxVal = words[i];
            max = i;
        }

    int j;
    int minVal = words[0];

    for (j = 1; j < argc-1; j++)
    {
        if (words[j] < minVal)
        {
            minVal = words[j];
            min = j;
        }
    }
    printf("Most difficult document: %s\n", fileName[max]);
    printf("Least difficult document: %s", fileName[min]);

    return 0;
}