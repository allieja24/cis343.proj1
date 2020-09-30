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

    int max;
    int min;


    while(fgets(input, sizeof(input), stdin) != NULL){
        
        int wrdAmt = 0;
        fileAmt++;

        FILE *fileN;

        scanf("%s", fileName[fileAmt - 1]);
        fileN = fopen(fileName[fileAmt - 1] ,"w");

        
    }

    return 0;
}

