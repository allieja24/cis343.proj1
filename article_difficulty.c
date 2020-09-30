/*Jarett Allie
September 1, 2020
Summary */

#include <stdio.h>  
#include <stdlib.h>

int main()  
{
    int fileAmt = 0;
    
    char input[1024];

    //string of file name
    char fileName[5][50];
    //amt of words
    int words[5];

    int max=0;
    int min=0;


    while(fgets(input, sizeof(input), stdin) != NULL){
        
        int wrdAmt = 0;
        fileAmt++;

        FILE *fileN;

        scanf("%s", fileName[fileAmt - 1]);
        fileN = fopen(fileName[fileAmt - 1] ,"w");

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
    }

    int i;   
    int maxVal = words[0];
    for (i = 1; i < sizeof(words) / sizeof(words[0]); i++) 
            if (words[i] > maxVal) 
                max = i;    
    i = 0;
    int minVal = words[0];

    for (i = 1; i < sizeof(words) / sizeof(words[0]); i++) 
        if (words[i] < minVal) 
            min = i; 

    printf("Most difficult document: %s", fileName[max]);
    printf("Least difficult document: %s", fileName[min]);
   

    return 0;
}

