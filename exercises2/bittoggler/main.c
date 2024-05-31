/******************************************************************************

Write a C program to input any number from user and toggle or invert or flip nth bit of the given
number using bitwise operator.
Example
Input
Input number: 22
Input nth bit to toggle: 1
Output
After toggling nth bit: 20 (in decimal)

*******************************************************************************/
#include <stdio.h>

void bitswitcher(int *num, int indexToToggle);

int main() {
    int num = 22;
    int indexToToggle = 1;
    bitswitcher(&num, indexToToggle);
    printf("%d", num);
    return 0;
}

void bitswitcher(int *num, int indexToToggle) {
    if (indexToToggle >= 0 && indexToToggle < 32) {
        // Toggle the nth bit
        //xor flips true to false, false totrue
        *num ^= (1 << indexToToggle);
    } else {
        printf("Invalid index");
    }
   
}
