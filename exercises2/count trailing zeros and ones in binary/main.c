/******************************************************************************

Write a C program to input a number from user and count total number of ones (1s) and zeros (0s)
in the given number using bitwise operator.
Example
Input
Input any number: 22
Output
Output number of ones: 3
Output number of zeros: 29

*******************************************************************************/
#include <stdio.h>
void countZerosAndOnes(int num, int *zeroCounter, int *oneCounter);

int main()
{   
    int zeroCounter;
    int oneCounter;
    int num;
    scanf("%d", &num);
    countZerosAndOnes(num, &zeroCounter, &oneCounter);
    printf("ones: %d\n", oneCounter);
    printf("zeros: %d", zeroCounter);
    return 0;
}


void countZerosAndOnes(int num, int *zeroCounter, int *oneCounter){
    for(int i = 0; i<=31; i++){
        if(num>>i&1==1){
            (*oneCounter)++;
        }else{
            (*zeroCounter)++;
            
        }
    }
}