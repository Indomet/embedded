/*
Write a program in C that reads 5 strings from a console, 
stores them in an array and finds the shortest string in the array.

 

The program should contain a function that takes as parameter the array, 
find the shortest string, remove it and return the array that is shorter by one element. 

 

The program should read the strings from the console. 

 

The program should have a separate function for finding and removing the string. 

 

The program should write the string that has been removed to the console. 
The program should also write all elements of the array before and after removal of the shortest string.
*/

#include <stdio.h> // printf, scanf library
#include <string.h> // strlen library
#include <stdlib.h> // malloc library

//define the maximum input size 200 chars + 1 null terminator
#define MAX_INPUT 201
// define maximum array size
#define MAX_ARRAY 5
//letting the program know that fuction exists after main
char** removeShortestElement(char** array);

int main(){
    //declare an array to store the strings
    char** array = malloc(sizeof(char*) * MAX_ARRAY);
   // ask user to input 5 strings
    for(int i=0; i<5; i++){
        //allocate memory to store the string
        array[i] = malloc(sizeof(char) * MAX_INPUT);
        //ask user to input a string
        scanf("%s", array[i]);
    }
    // call the function to remove the shortest string
    removeShortestElement(array);

    printf("Array after removal:\n");
    //loop through the array after removal and print the strings
    for(int i = 0; i < MAX_ARRAY-1; i++){
        printf("%s\n", array[i]);
    }
    //return 0 to exit program successfully
    return 0;
}
//function to remove the shortest string from the array
char** removeShortestElement(char** array){
    //declare variable to store shortest string
    int shortestIndex = 0;
    //loop through the array to find the shortest string
    for(int i = 0; i < 5; i++){
        //if the current string is shorter than the shortest string 
        if(strlen(array[i]) < strlen(array[shortestIndex])){
            // make the current string the shortest string
            shortestIndex = i;
        }
    }
    printf("Shortest string removed: %s\n", array[shortestIndex]);
    //loop through the array to remove the shortest string
    for(int i = shortestIndex; i < MAX_ARRAY; i++){
        //move the strings to where shortest string was
        array[i] = array[i+1];
    }

    //return the array after removal
    return array;
}