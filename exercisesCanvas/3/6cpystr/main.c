#include <stdio.h> //standard input/output library
#include <stdlib.h> //standard library
#include <string.h> //string library
//define the maximum size of the string
#define MAX 20

void copyString(char* destination, char* source); // Function that copies string from source to destination.

int main(int argc, char* argv[]) {
    // Declare the string1
    char string1[MAX];
    // Declare the string2
    char string2[MAX];
    // Declare the string3
    char string3[MAX];
    fgets(string1, MAX, stdin); // Read a single line of string to string1 from stdin, which can be both typed or redirected from myfile.txt

    // Using strcpy
    strcpy(string2, string1);
    printf("Copied string using strcpy: %s\n", string2);

    // Using my function
    copyString(string3, string1);
    printf("Copied string using copyString: %s\n", string3);
    return 0;
}

void copyString(char* destination, char* source) { // Function that copies one string to another
    // set i to 0
    int i = 0;
    while (source[i] != '\0') { // Loop while it doesn't arrive at the null terminator
        destination[i] = source[i]; // Copy over the charcter
        i++; // increment i
    }
    destination[i] = '\0'; // Add the null terminator for the new string
}