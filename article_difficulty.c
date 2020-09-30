#include <stdio.h>  
#include <stdlib.h>

int main()  
{
    FILE *file1;
    FILE *file2;

    int wrdAmt = 1;
    int wrdAmt2 = 1;

    //file1
    char fileName[20];

    scanf("%s",fileName);

    file1 = fopen(fileName,"r");

    char c;

    c = fgetc(file1);

    while(c != EOF){
        
        if(c == ' ' || c == '\n'){
            wrdAmt++;
        }

        c = fgetc(file1);
    }

    fclose(file1);

    //file2
    char fileName2[20];

    scanf("%s",fileName2);

    file2 = fopen(fileName2,"r");

    char c2;

    c2 = fgetc(file2);

    while(c2 != EOF){
        
        if(c2 == ' ' || c2 == '\n'){
            wrdAmt2++;
        }

        c2 = fgetc(file2);
    }

    fclose(file2);

    //compare

    if(wrdAmt > wrdAmt2){
        printf("Most difficult document: %s", file1);
        printf("Least difficult document: %s", file2);
    }
    else if(wrdAmt < wrdAmt2){
        printf("Most difficult document: %s", file2);
        printf("Least difficult document: %s", file1);
    }
    else{
        printf("Most difficult document: %s", file1);
        printf("Least difficult document: %s", file1);
    }

    return 0;
}

