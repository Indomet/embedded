#include <stdio.h>     // Include the standard input-output library for basic input and output operations.
#include <string.h>    // Include the string library for string manipulation functions.

void print_spaces(int num) {   // Define a function print_spaces that takes an integer parameter num.
    for (int i = 0; i < num; i++) {   // Loop from 0 to num - 1.
        printf(" ");   // Print a space character.
    }
}

int main() {   // Define the main function.
    char text[] = "Cisbest";   // Declare and initialize a character array named text with the string "Cisbest".
    int len = strlen(text);   // Determine the length of the string stored in text and store it in len.

    for (int i = 0; i < len - 1; i++) {   // Loop from 0 to len - 2.
        if (i == 0) {   // Check if i is equal to 0.
            print_spaces(1);   // Call the print_spaces function with argument 1.
        }
        print_spaces(2 * (len - i - 1));   // Call the print_spaces function with argument 2 * (len - i - 1).

        printf("%c", text[i]);   // Print the character at index i from the text array.

        if (i != 0) {   // Check if i is not equal to 0.
            print_spaces(4 * i + 1);   // Call the print_spaces function with argument 4 * i + 1.
            if (i != len) {   // Check if i is not equal to len.
                printf("%c", text[i]);   // Print the character at index i from the text array.
            }
        }

        if (i == (len - 2)) {   // Check if i is equal to len - 2.
            printf("\n");   // Print a newline character.
            for (int j = len; j >= 0; j--) {   // Loop from len to 0.
                printf("%c", text[j]);   // Print the character at index j from the text array.
                print_spaces(1);   // Call the print_spaces function with argument 1.
            }
            for (int k = 1; k < len; k++) {   // Loop from 1 to len - 1.
                printf("%c", text[k]);   // Print the character at index k from the text array.
                print_spaces(1);   // Call the print_spaces function with argument 1.
            }
        }

        printf("\n");   // Print a newline character.
    }

    return 0;   // Return 0 to indicate successful program execution.
}

