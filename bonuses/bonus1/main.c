// Write a program that counts the number of 0s and 1s in the binary representation of a decimal number. 

 

// Your program should take a decimal number as argument. Then it should print the decimal number, 
//it's binary representation and then count the number of 0s and 1s.

// For example, for the following command:

// main.exe 3
// The output should be: 

// Number: 3
// Binary: 0b11
// Number of 0s: 0
// Number of 1s: 2
// In this task, you must use bit operations. You are not allowed to convert the number to strings or arrays of any sort. 
//Leading 0s should not be counted (e.g., 0b0011 should return "Number of 0s: 0; Number of 1s: 2"). 

// Please remember that the program should handle errors:

// When the argument is empty
// When the argument is not a number (e.g., 0x11)

#include <stdio.h> // included stdio for printing
#include <stdlib.h> // atoi
#include <ctype.h> //isdigit
 // this is hee to let the program know about the function existing after main
void binaryConverter(int number, int *zerocounter, int *oneCounter);

int main(int argc, char *argv[]){ // argc counts arguments and argv is the argument itself
 // if the argument is not given while executing the program, telll user to execute with an argument
    if(argc==1){ 
        printf("Error: No number provided. Please provide a number as a command line argument.\n");
    //return 0 to indicate that the program was successful
        return 0; 
    }
   // if the argument is not digit tell user to enter the digit
   // loop through in each character inside argv[1] until it hits \0, it tells the pogram that it is end of the char
    for (int i = 0; argv[1][i]!= '\0'; i++){
    //check every single character if they are digit or not, if even one of the characters are char, tell the users to enter int
        if (!isdigit((int)argv[1][i])){
            printf("Error: Invalid number.\n");
                //return 0 to indicate that the program was successful
            return 0;
        }
    }
    // this reads the argument array and converts it to int
    int number = atoi(argv[1]);

    printf("Number: %d\n", number);
    int oneCounter;
    int zeroCounter;

    printf("Binary: ");
    // this calls the binaryconverter method and passes in the number argument given by the user, 
    // &zeroCounter and &oneCounter is the address of the variables, (I imagine them as empty boxes that can be filled)
    binaryConverter(number, &zeroCounter, &oneCounter);

    printf("Number of 0s: %d\n", zeroCounter);
    printf("Number of 1s: %d\n", oneCounter);
    // returning 0 indicates that the program is succesfull
    return 0; 
}
// this method recieves the given number and the other two variables are pointing to the box
void binaryConverter(int number, int *zeroCounter, int *oneCounter){ // an integer is 32 bit and 32 bit is 4 byte
// making the value of zerocounter 0
    *zeroCounter=0;
    // making the value of onecounter 0
    *oneCounter=0;   
    printf("0b");
    // an integer has 32 bit we start looping from very last bit until 0 
    for(int i = 31; i >= 0; i--){ 
    // shift the bits of the number to the right by i places then in the next step we compare its last bit
        int binary = number>>i;
        // if the binary representation of the number ends with 1 then we count it as 1
        if(binary & 1){  
            printf("1");
            // we update the counter by one every time there is one
            (*oneCounter)++;
            // if the binary representation of the number is 10 then we count it as 0
        }else if(binary){
            printf("0");
            // we update the counter by one everythime there is one
            (*zeroCounter)++;
        }
    }
    printf("\n");
}
