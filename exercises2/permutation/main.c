#include <stdio.h> // Including standard input/output header file
#include <string.h> // Including string manipulation functions header file

void swap(char *a, char *b); // Function prototype for swapping two characters
void permutate(char *string, int startingPoint, int endingpoint); // Function prototype for generating permutations

int main() { // Main function

    char string[] = "abcd"; // Initializing a character array with string "abcd"

    permutate(string, 0, strlen(string)); // Calling the permutation function

    return 0; // Returning 0 to indicate successful execution
}

void permutate(char *string, int startingPoint, int endingpoint) { // Function definition for permutation

    if (startingPoint == endingpoint) { // Base case: if starting and ending points are equal
        printf("%s ", string); // Print the current permutation
    } else { // Recursive case
        for (int i = startingPoint; i < endingpoint; i++) { // Loop over the substring
            swap((string + startingPoint), (string + i)); // Swap characters
            permutate(string, startingPoint + 1, endingpoint); // Recursively call permutate function
            swap((string + startingPoint), (string + i)); // Backtrack by swapping again
        }
    }
}

void swap(char *a, char *b) { // Function definition for swapping two characters
    char temp = *b; // Store the value of the second character in a temporary variable
    *b = *a; // Assign the value of the first character to the second character
    *a = temp; // Assign the value of the temporary variable to the first character
}
