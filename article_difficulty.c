/*Jarett Allie
September 1, 2020
Summary */

#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

int main()  
{
    int fileAmt;
    char input[264];
    int words[20];

    char max[264];
    char min[264];


    while(fgets(input, sizeof(input), stdin) != NULL){
        int wrdAmt = 0;
        fileAmt++;

        char fileName[264];

        FILE *fileN;
        scanf("%s", fileName);
        strcat(fileName,".txt");
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

        words[fileAmt - 1] = wrdAmt;

        int i;
        int maxVal = words[0];

        for (i = 1; i < wrdAmt; i++) 
            if (words[i] > maxVal) 
                maxVal = words[i]; 

        if(maxVal = wrdAmt){
            strcpy(max, fileName);
        }

        i = 0;
        int minVal = words[0];

        for (i = 1; i < wrdAmt; i++) 
            if (words[i] < minVal) 
                minVal = words[i]; 

        if(minVal = wrdAmt){
            strcpy(min, fileName);
        }
    }


    printf("Most difficult document: %s", max);
    printf("Least difficult document: %s", min);
   
    return 0;
}

