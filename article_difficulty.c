/*Jarett Allie
September 1, 2020
Summary */

#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

int main()  
{
    int fileAmt;
    
    char input[260];
    //string of file name
    char* fileName[5];
    //amt of words
    int* words[5];

    int max;
    int min;


    while(fgets(input, sizeof(input), stdin) != NULL){
        int wrdAmt = 0;
        fileAmt++;

        FILE *fileN;

        fileName[fileAmt - 1] = (char*) malloc(30);

        scanf("%s", fileName[fileAmt - 1]);
        strcat(fileName[fileAmt -1],".txt");
        fileN = fopen(fileName ,"w+");

        char nextCh;

        nextCh = fgetc(fileN);

        while(nextCh != EOF){
        
            if(nextCh == ' ' || nextCh == '\n'){
                wrdAmt++;
            }
            nextCh = fgetc(fileN);
        }

        fclose(fileN);

        words[fileAmt - 1] = (int*) malloc (4);
        words[fileAmt - 1] = wrdAmt;
    }

        int wordArrLen = sizeof(words) / sizeof(words[0]);

        int i;
        
        int maxVal = words[0];

        for (i = 1; i < wordArrLen; i++) 
            if (words[i] > maxVal) 
                max = i; 

        i = 0;
        int minVal = words[0];

        for (i = 1; i < wordArrLen; i++) 
            if (words[i] < minVal) 
               min = i; 

    printf("Most difficult document: %s", fileName[max]);
    printf("Least difficult document: %s", fileName[min]);
   
    free(fileName);
    free(words);

    return 0;
}

