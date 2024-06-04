/******************************************************************************

Write a C program to concatenate two strings in single string. You cannot use the built-in function
here. You should use dynamic memory allocation at the heap.
Example
Input
Input string1: I love
Input string2: DIT632
Output
Concatenated string: I love DIT632

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void concatanate(char *string1, char *string2);
int main()
{
    // printf("Hello World");
    
    // char string1[] ="i love";
    // char string2[] = "myself";
    char string1[100];
    char string2[100];

    fgets(string1, sizeof(string1),stdin);
    fgets(string2, sizeof(string2),stdin);
    concatanate(string1,string2 );
    return 0;
}

void concatanate(char *string1, char *string2){
    
    char *newchar=malloc((strlen(string1)+strlen(string2) +1));
    
    int i = 0;
    int j = 0;
    
    while(string1[i] !='\n'){ //'\0' if used without fgets
        newchar[i]=string1[i];
        i++;
        
    }
    
    
    while(string2[j]!='\n'){//'\0' if used without fgets
        newchar[i+j]=string2[j];
        j++;
    }
    // newchar[i+j] ='\0';
    printf("%s", newchar);

    
}
