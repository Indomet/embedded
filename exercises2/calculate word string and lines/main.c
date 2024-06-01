/******************************************************************************

Write a program to read a string from the console/stdin and count the number of chars, words, and
lines, and print these quantities

*******************************************************************************/
//Write a program to read a string from the console/stdin and count the number of chars, words, and
// lines, and print these quantities

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //isspace
#include <stdbool.h>
void calculateStringlength();

int main()
{
calculateStringlength();

    return 0;
}

void calculateStringlength(){
 char input[100]; // Assuming a buffer size of 100 for this example
    int i = 0;
    char c;

    // Read input character by character using getchar
    while ((c = getchar()) != EOF && i < sizeof(input) - 1) {
        input[i++] = c;
    }

    // Null-terminate the string
    input[i] = '\0';
    
    int characters = 0;
    int lines = 1;
    int words = 0;
    int lastchar=' ';
    bool inWord = false;
    for(int i = 0; input[i] !='\0'; i++ ){
        if(input[i]!= '\n'){
        characters++;    
        }
        if(input[i] =='\n'){
            lines++;
        }
        
        // if( input[i] == '\n'|| input[i]== ' '|| input[i+1] ==EOF){
        // words++;    
        // }
        // lastchar=input[i];
        
         // If current character is a space or punctuation,
        // it marks the end of a word if inWord is true
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n' || input[i] == '\r' || input[i] == '\v' || input[i] == '\f' || input[i] == '.' || input[i] == ',' || input[i] == '?' || input[i] == '!' || input[i] == ';' || input[i] == ':' || input[i] == '-') {
            if (inWord) {
                inWord = false;
                words++;
            }
        }
        // If current character is a letter or digit and not in a word already,
        // it marks the start of a new word
        else if (!inWord) {
            inWord = true;
        }
    }

    // If the last character in the string is part of a word, increment the count
    if (inWord){
        words++;        
    }


    
    

    printf("\ncharacters: %d\n", characters);
    printf("word: %d\n", words);
    printf("lines: %d\n", lines);
    // Print the input
    printf("%s", input);

}


// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

// #define MAX_LENGTH 1000

// int main() {
//     char input[MAX_LENGTH];
//     int charCount = 0, wordCount = 0, lineCount = 0;
//     char lastChar = '\n'; // Assuming the input starts with a new line

//     // Read input string from console
//     printf("Enter some text (Ctrl+D to end):\n");

//     while (fgets(input, MAX_LENGTH, stdin) != NULL) {
//         for (int i = 0; input[i] != '\0'; i++) {
//             char currentChar = input[i];
//             charCount++;

//             // Count words
//             if (isspace(currentChar) && !isspace(lastChar))
//                 wordCount++;

//             // Count lines
//             if (currentChar == '\n')
//                 lineCount++;

//             lastChar = currentChar;
//         }
//     }

//     // Increment line count if input doesn't end with a new line
//     if (lastChar != '\n')
//         lineCount++;

//     printf("\nNumber of characters: %d\n", charCount);
//     printf("Number of words: %d\n", wordCount);
//     printf("Number of lines: %d\n", lineCount);

//     return 0;
// }





