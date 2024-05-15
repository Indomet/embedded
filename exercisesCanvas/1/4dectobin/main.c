#include <stdio.h> // included stdio for printing
#include <stdlib.h> // atoi
#include <ctype.h> //isdigit
#include <math.h> //include this for log2 function
#include <limits.h> // this is to get max long number
#include <string.h> // for strcmp
 // this is hee to let the program know about the function existing after main
void binaryConverter(long number);

int main(int argc, char *argv[]){ // argc counts arguments and argv is the argument itself
 // if the argument is not given while executing the program, telll user to execute with an argument
    if(argc==1){ 
        printf("Error: No number provided. Please provide a number as a command line argument.\n");
        printf("Enter -h for help\n");
        return 2; 
    }
   // if the argument is -h show the help page
    if(strcmp(argv[1],"-h")==0){
        printf("provide one argument, and the argument needs to be a number that is less than or equal to 2147483647\n");
        return 2;
    }

    // if the argument is not digit tell user to enter the digit
   // loop through in each character inside argv[1] until it hits \0, it tells the pogram that it is end of the char
    for (int i = 0; argv[1][i]!= '\0'; i++){
    //check every single character if they are digit or not, if even one of the characters are char, tell the users to enter int
        if (!isdigit((int)argv[1][i])){
            printf("Error: Invalid number.\n");
            printf("Enter -h for help\n");
            return 2;
        }
    }

    char *endptr;
    // this reads the argument array and converts it to long
    // 10 because the base is 10
    long number = strtol(argv[1], &endptr, 10 );

    int integer =atoi(argv[1]);
    // if the number given is bigger than
    if((integer > 2147483647 || integer < 0) ){
        printf("The number provided is bigger than max long value pls provide under 2147483647\n");
        printf("Enter -h for help\n");
        return 2;
    }

    // this calls the binaryconverter method and passes in the number argument given by the user, 
    binaryConverter(number);

    // returning 0 indicates that the program is succesfull
    return 0; 
}

// this method recieves the given number
void binaryConverter(long number) {
    // calcuklating the number of bits needed for the given number
    int numBits = log2(number + 1);

    // if the bit is smaller than 8 spare 8 bits then if it is smallar than 16 spare 16 otherwise 32
    int totalBits = numBits < 8 ? 8 : (numBits < 16 ? 16 : 32);

    // going through each bit from the most significant bit to the least significant bit
    for(int currentBit = totalBits - 1; currentBit >= 0; currentBit--) {
        //shifting the bits of the number to the right by currentBit places
        int currentBitValue = number >> currentBit;
        // if the binary representation of the number ends with 1 then we count it as 1
        if(currentBitValue & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}//benim