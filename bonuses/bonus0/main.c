// In this assignment, you must use the command line to provide the name of the person who is to be greeted. 

// Example:

// Command line: main.exe Asim

// Output: "Hello Asim, how is your day today?"
// Additional requirements:

// If the program does not receive any name as the command line argument, it should output: "No command line argument provided, please provide a name. "
// The name should be at most 50 characters - for longer names, the output should be "Name too long, max 50 characters"
// The name should be at least 3 characters - for shorter names, the output should be "Name too short, min 3 characters"

#include <stdio.h>
#include <string.h> // this library is used to get the length of the argument

int main(int argc, char *argv[]){ // argc stands for argument count and argv stands for argument itself
    if(argc == 1){ // we check if it is equal to one since the program itself is already 1 argument
        printf("No command line argument provided, please provide a name.\n");
    }
    else if(strlen(argv[1]) > 50){ // checks if the argument's character is more than 50
        printf("Name too long, max 50 characters\n");
    }
    else if(strlen(argv[1])< 3){ // checks if the argument's character is less than 3
        printf("Name too short, min 3 characters\n");
    } else { // if the provided argument is not shorter than 3 and more than 50 we print it
        printf("Hello %s, how is your day today?\n", argv[1]);
    }
    return 0; //shows thaat successful execution of the program by returning 0 to the operating system
}