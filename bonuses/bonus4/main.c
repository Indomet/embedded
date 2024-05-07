/*
Write a program in C to print all permutations of a given string using pointers. 
The string should be provided as an argument to your program. The limit of the number of characters 
in the input is 10. The program should store all the permutations in a large array. 

The code should be commented. 

For the input

permuter.exe abcd
The expected output should be:

All permutations of the string abcd are:  abdc  acbd  acdb  adcb  adbc  bacd  badc  bcad  bcda  bdca  
bdac  cbad  cbda  cabd  cadb  cdab  cdba  dbca  dbac  dcba  dcab  dacb  dabc
*/

#include <stdio.h>// printf library
#include <stdlib.h> //malloc library
#include <string.h> //strlen library
// this is to let the program know that we have a function after main
void permutate(char* input, int startingIndex, int endingIndex, int* count, char** array);
// this is to let the program know that we have a function after main
void swap(char* a, char* b);

int main(int argc, char* argv[]) {
    //checking if the array arguments are valid by checking the length of the string and the number of arguments
    if (argc != 2 || strlen(argv[1]) > 10) {
        printf("invalid");
        //return 0 if the arguments are invalid to exit the program successfully
        return 0;
    }
    // crreate an array of 10 characters
    char input[10];
    //copy the input to a new array
    strcpy(input, argv[1]);
    //create a counter variable to to store number of permutations
    int permutationCounter = 1;
    // okay here we calculate the possible permutations of the input size
    for (int i = 0; i < strlen(input); i++) {
        // we multiply the counter by i + 1
        permutationCounter *= i + 1;
    }
    // array of pointers to store the permutations
    char** array = malloc(permutationCounter * sizeof(char*));

    //create a counter variable to store the number of permutations
    int count = 0;
    // call the permutate function to get the permutations
    permutate(input, 0, strlen(input) - 1, &count, array);

    // print the number of permutations by going through the array
    for (int i = 0; i < count; i++) {
        printf("%s ", array[i]);
    }
    // free the memory allocated for the array
    for (int i = 0; i < count; i++) {
        free(array[i]);
    }
    // free the memory allocated for the array
    free(array);
}
// this function recieves the input and the starting and ending index of the input
void permutate(char* input, int startingIndex, int endingIndex, int* count, char** array) {

    // this is the base case so when each step of the permutation is complete we print for now
    if (startingIndex == endingIndex) {
        // allocate memory for inputs in the array ( +1 is to allocate memory for the null terminator)
        array[*count] = malloc((strlen(input) + 1) * sizeof(char));
        // copy the input to the array
        strcpy(array[*count], input);
        // increment the counter to go to the next index in the next permutation
        (*count)++;
        
    } else {
        // this is the recursive case for the permutation the for loop starts from startingindex and goes to ending index
        for (int i = startingIndex; i <= endingIndex; i++) {
            // we move the pointer by adding startingIndex to input
            // this is basically switching characters
            swap((input + startingIndex), (input + i));
            // this will call the function itself but this time starting point wil be the next index
            permutate(input, startingIndex + 1, endingIndex, count, array);
            // this is backtracking so it will swap back what has been swapped in the previous step
            // so it restores the original state before moving to next permutation
            swap((input + startingIndex), (input + i));
        }
    }
}
// this function swaps the characters
void swap(char* a, char* b) {
    // create a temp to store one of variables
    char temp;
    // store a in temp
    temp = *a;
    // store b in a
    *a = *b;
    // store a (temp) in b
    *b = temp;
}