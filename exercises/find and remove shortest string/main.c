/******************************************************************************
Write a program in C that reads 10 strings from a console, stores them in an array and finds the
shortest string in the array.

The program should contain a function that takes as parameter the array, find the shortest string,
remove it and return the array that is shorter by one element.

The program should read the strings from the console. <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
The program should have a separate function for finding and removing the string.<<<<<<<<<<<<<<<<<<<<<<<<<
The program should write the string that has been removed to the console. The program should<<<<<<<<<<<<<<
also write all elements of the array before and after removal of the shortest string.<<<<<<<<<<<<<
You can use the online compiler for this question here: www.onlinegdb.com
The program should contain the following:
* correct functionality (as specified above) - 3 points<<<<<<<<
* comments - 3 points<<<<<<<<<
* function to find and remove the element - 2 points<<<<<<
* main to test the program - 2 points<<<<<<<<<<
* safety checks - 2 points<<<<<<<
Please remember to paste the code from onlinegdb to the form below.

*******************************************************************************/
#include <stdio.h>       // Include standard input-output header file
#include <stdlib.h>      // Include standard library header file
#include <string.h>      // Include string manipulation functions
#define MAX 10           // Define a macro for the maximum size of the array

void removeShortestString(int shortestIndex, char **array);  // Function prototype for removeShortestString
int findShortestString(char **array);                        // Function prototype for findShortestString

int main() {
    // char input1[100];   // Commented out code, not used in this version
    // scanf("%s", input1);
    // printf("%s", input1);
    
    char **array = malloc(sizeof(char*) * MAX);  // Allocate memory for an array of character pointers
    if (array == NULL) {                          // Check if memory allocation failed
        fprintf(stderr, "Memory allocation failed for array.\n");  // Print error message to stderr
        return 1;                                  // Return with an error code
    }
    
    for(int i = 0; i < MAX; i++){  // Loop to read input strings
        array[i] = malloc(sizeof(char*) * 500);  // Allocate memory for each string
        scanf("%s", array[i]);                    // Read a string from standard input
    }
    
    printf("before removal\n");  // Print a message
    
    for(int i = 0; i < MAX; i++){  // Loop to print strings before removal
        printf("%s\n", array[i]);   // Print each string
    }
    
    int shortestIndex = findShortestString(array);  // Find the index of the shortest string
    removeShortestString(shortestIndex, array);     // Remove the shortest string
    
    printf("after removal\n");  // Print a message
    
    for(int i = 0; i < MAX-1; i++){  // Loop to print strings after removal
        printf("%s\n", array[i]);     // Print each string
    }

    return 0;  // Return success
}

int findShortestString(char **array) {  // Function definition to find the index of the shortest string
    int shortestIndex = 0;  // Initialize index of shortest string to 0
    for(int i = 0; i < MAX; i++){  // Loop through each string in the array
        if(strlen(array[i]) < strlen(array[shortestIndex])){  // Compare lengths of strings
            shortestIndex = i;  // Update index of shortest string if current string is shorter
        }
    }
    printf("string removed: %s\n", array[shortestIndex]);  // Print the shortest string
    return shortestIndex;  // Return index of shortest string
}

void removeShortestString(int shortestIndex, char **array) {  // Function definition to remove the shortest string
    for(int i = shortestIndex; i < MAX; i++){  // Loop through elements from shortestIndex
        array[i] = array[i+1];  // Shift each element to the left
    }
}



// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX 10
// #define MAX_STRING_LENGTH 500

// void removeShortestString(int shortestIndex, char **array);
// int findShortestString(char **array);

// int main()
// {
//     char **array = malloc(sizeof(char*) * MAX);
//     if (array == NULL) {
//         fprintf(stderr, "Memory allocation failed for array.\n");
//         return 1;
//     }

//     for (int i = 0; i < MAX; i++) {
//         array[i] = malloc(sizeof(char) * MAX_STRING_LENGTH);
//         if (array[i] == NULL) {
//             fprintf(stderr, "Memory allocation failed for string %d.\n", i);
//             // Free memory allocated so far
//             for (int j = 0; j < i; j++) {
//                 free(array[j]);
//             }
//             free(array);
//             return 1;
//         }
//         printf("Enter string %d: ", i+1);
//         if (scanf("%499s", array[i]) != 1) {
//             fprintf(stderr, "Error reading input.\n");
//             // Free memory allocated so far
//             for (int j = 0; j <= i; j++) {
//                 free(array[j]);
//             }
//             free(array);
//             return 1;
//         }
//     }

//     printf("before removal\n");
//     for (int i = 0; i < MAX; i++) {
//         printf("%s\n", array[i]);
//     }

//     int shortestIndex = findShortestString(array);
//     removeShortestString(shortestIndex, array);

//     printf("after removal\n");
//     for (int i = 0; i < MAX - 1; i++) {
//         printf("%s\n", array[i]);
//     }

//     // Free memory
//     for (int i = 0; i < MAX - 1; i++) {
//         free(array[i]);
//     }
//     free(array);

//     return 0;
// }

// int findShortestString(char **array)
// {
//     int shortestIndex = 0;
//     for (int i = 0; i < MAX; i++) {
//         if (strlen(array[i]) < strlen(array[shortestIndex])) {
//             shortestIndex = i;
//         }
//     }
//     printf("string removed:  %s\n", array[shortestIndex]);
//     return shortestIndex;
// }

// void removeShortestString(int shortestIndex, char **array)
// {
//     for (int i = shortestIndex; i < MAX - 1; i++) {
//         strcpy(array[i], array[i + 1]);
//     }
// }



