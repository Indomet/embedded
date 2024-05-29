/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>     // Include standard input/output library
#include <string.h>    // Include string manipulation functions

void checkIfAnagram(char *input1, char *input2); // Function prototype for checking if two strings are anagrams
void sort(char *input);  // Function prototype for sorting a string

int main()
{
    char input1[] = "spare"; // First input string
    char input2[] = "pears"; // Second input string
    // scanf("%s", input1); // Allowing user input for first string
    // scanf("%s", input2); // Allowing user input for second string
    checkIfAnagram(input1, input2); // Call function to check if the two strings are anagrams
    return 0; // Return 0 to indicate successful execution
}

// Function to check if two strings are anagrams
void checkIfAnagram(char *input1, char *input2)
{
    int asciiInput1;  // Variable to store the sum of ASCII values of characters in first string
    int asciiInput2;  // Variable to store the sum of ASCII values of characters in second string
    char *temp1 = input1;  // Temporary pointer to traverse first string
    char *temp2 = input2;  // Temporary pointer to traverse second string
    
    // Loop through both strings until reaching the end of either string
    while (*temp1 != '\0' || *temp2 != '\0') {
        asciiInput1 += (int)*temp1; // Add ASCII value of current character in first string to asciiInput1
        asciiInput2 += (int)*temp2; // Add ASCII value of current character in second string to asciiInput2
        temp1++; // Move to the next character in first string
        temp2++; // Move to the next character in second string
    }
    
    // Check if the sums of ASCII values of characters in both strings are equal
    if (asciiInput1 == asciiInput2) {
        printf("%s and %s are anagrams", input1, input2); // Print message indicating that the strings are anagrams
    } else {
        printf("%s and %s are not anagrams", input1, input2); // Print message indicating that the strings are not anagrams
    }
}


// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// void checkIfAnagram(char *input1, char *input2);
// char *sort (char *input);
// int main()
// {
//     char input1[]="spare" ;
//     char input2[]="pears";
//     // scanf("%s", input1);
//     // scanf("%s", input2);
//     checkIfAnagram(input1,input2);
    
//         // printf("%s", input2);
//     return 0;
// }

// char *sort (char *input){
//     // Allocate memory for a copy of the input string
//     char *copy = strdup(input);
//     // Sort the copy
//     int length = strlen(copy);
//     for (int i = 0; i < length - 1; i++) {
//         for (int j = i + 1; j < length; j++) {
//             if (copy[i] > copy[j]) {
//                 char temp = copy[i];
//                 copy[i] = copy[j];
//                 copy[j] = temp;
//             }
//         }
//     }

//     // Print the sorted copy
//     printf("Sorted Array: %s\n", copy);
//     return copy;
//     // Free the dynamically allocated memory
//     free(copy);
// }

// void checkIfAnagram(char *input1, char *input2){
//     if(strlen(input1) != strlen(input2)){
//         printf("%s and %s are not anagram", input1,input2);
//     }

//         char *temp1 = sort(input1);
           
//         char *temp2 =sort(input2);
//     if (strcmp(temp1, temp2) == 0)
//     {
//         printf("%s and %s are anagrams\n", input1, input2);
//     }
//     else
//     {
//         printf("%s and %s are not anagrams\n", input1, input2);
//     }
    
// }

