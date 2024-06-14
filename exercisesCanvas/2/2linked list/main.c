#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

enum DIRECTION { // Define Direction enums in order of clockwise rotation.
    N, // North(0)
    E, // East(1)
    S, // South(2)
    W // West(3)
};

typedef struct { // Define structure called robot with x,y position, and direction.
    int xpos; // Define x postion as integer
    int ypos; // Define y postion as integer
    enum DIRECTION dir; // Define enum as DIRECTION
} ROBOT; // Name struct alias to ROBOT

char endCharacter = 'Q'; // Define end character
void move(ROBOT* robot); // Define function that moves the robot one unit towards the direction its facing.
void turn(ROBOT* robot); // Define function that turns the robot 90 degrees clockwise.
bool setCoordinate(int* coor); // Define function that validates and sets the starting coordinate from user input.
bool setInstruction(char string[], bool* exit); // Define function that validates and saves a string of instructions to string[] from user input.

int main(int argc, char* argv[]) { // Main function
    ROBOT optimusPrime = { 0, 0, N }; // Initialize robot with default values, 0, 0, facing North.
    int xStart = 0; // Initialize variable to store xstarting position
    int yStart = 0; // Initialize variable to store ystarting position
    bool exit = false; // Initialize variable to store whether program should exit.
    char instruction[CHAR_MAX]; // initialize char array to store user instruction.

    do { // Do while exit = false
        printf("Set starting x coordinate between 0-99: ");
        if (setCoordinate(&xStart) == false) // If setCoordinate returns false then its invalid
            return 1; // Return 1 means program exit with error
        printf("Set starting y coordinate between 0-99: ");
        if (setCoordinate(&yStart) == false) ////If setCoordinate returns false then its invalid
            return 1; // Return 1 means program exit with error

        optimusPrime.xpos = xStart; // set xpos of robot to x value that user inputted
        optimusPrime.ypos = yStart; // set ypos of robot to y value that user inputted
        printf("Set robot starting coordinates: x=%d, y=%d, facing North.\n", xStart, yStart);

        printf("Input instructions, m=Move 1 towards current direction, t=Turn 90 degrees clockwise, %c to Exit: ", endCharacter);
        while (setInstruction(instruction, &exit) == false) // While user input instruction string is invalid, keep asking. must be m, t, or the end character defined earlier.
            printf("Invalid instruction, try again: ");
        printf("Instruction: %s\n", instruction);

        for (int i = 0; i < strlen(instruction); i++) { // Loop through each char in the instruction string.
            if (instruction[i] == 'm') { // If instruction is move
                move(&optimusPrime); // Move robot
            } else if (instruction[i] == 't') { // If instruction is turn
                turn(&optimusPrime); // Turn the robot
            }
        }
        printf("The new position of the robot is x=%d, y=%d.\n", optimusPrime.xpos, optimusPrime.ypos);

    } while (!exit); // While not exit, keep looping
    return 0; // Return 0 means the program executed successfully.
}

void move(ROBOT* robot) { // Function that moves the robot
    switch (robot->dir) // Access dir attribute of robot
    {
    case N: // If robot.dir = N
        robot->ypos++; // Increment robot y coordinate
        break;
    case E: // If robot.dir = E
        robot->xpos++; // Increment robot x coordinate
        break;
    case S: // If robot.dir = S
        robot->ypos--; // Decrement robot y coordinate
        break;
    case W: // If robot.dir = N
        robot->xpos--; // Decrement robot x coordinate
        break;
    default: // Default case
        break;
    }
}

void turn(ROBOT* robot) { // Function that turns the robot 90 degrees clockwise
    robot->dir = (robot->dir + 1) % 4; // Robot (dir + 1) % 4 would give a value in the range of 0-3, representing the 4 direction enums. +1 to increment, and % 4 to go from West back to North.
}

bool setCoordinate(int* coor) { // Function that scans input and validates an int coordinate
    if (scanf("%d", coor) == 0) { // If scanf returns 0 it means it failed to read in the specified format.
        // https://www.geeksforgeeks.org/scanf-in-c/
        // The scanf in C returns three types of values:
        //>0: The number of values converted and assigned successfully.
        // 0: No value was assigned.
        //<0: Read error encountered or end-of-file(EOF) reached before any assignment was made.
        printf("Invalid value\n");
        return false; // Return false to indicate invalid coor
    } else if (*coor < 0 || *coor > 99) { // Check if value is outside accepted starting range.
        printf("Value outside range.\n");
        return false; // Return false to indicate invalid coor
    }
    return true; // Return true to indicate valid coor
}

bool setInstruction(char string[], bool* exit) { // Function that reads, validates, and saves instruction to robot.
    if (scanf("%s", string) == 0) { // If scanf returns 0 it means it failed to read in the specified format.
        printf("Invalid value\n");
        return false; // Return false to indicate invalid coor
    } else if (strlen(string) > CHAR_MAX) { // If instruction is too long
        printf("Instruction too long!\n");
        return false; // Return false to indicate invalid coor
    } else {
        for (int i = 0; i < strlen(string); i++) { // Loop through each character of the string
            if (string[i] == endCharacter) { // If char is equal to end character
                printf("Exiting program after executing instruction.\n");
                *exit = true; // Set exit to true if endchar has been read, which will exit the program after executing instructions before this character.
            } else if (string[i] != 'm' && string[i] != 't' && string[i] != endCharacter) { // If instruction string contains unrecongized characters.
                printf("Instruction must only contain 'm', 't', or %c to quit the program.\n", endCharacter);
                return false; // Return false to indicate invalid coor
            }
        }
    }
    return true; // Return true to indicate valid coor
}

// #include <stdio.h> // library for ptinting
// #include <string.h>// library to get length

// //enum for the directions
// enum DIRECTION { N,E,S,W };
// // making our own robot struct
// typedef struct {
//     int xpos;
//     int ypos;
//     enum DIRECTION dir;
// } ROBOT;
// // this is just letting the programme know something exists after main
// void move(ROBOT* robot);
// // this is just letting the programme know something exists after main
// void turn(ROBOT* robot);
// // this is just letting the programme know something exists after main
// void clear_buffer();

// int main() {
//     // creating and initializing the robot
//     ROBOT robot = { 0, 0, N }; // instead of initializing one by one

//     //input from user
//     char instructions[100];
//     // intput to end the program
//     char endChar;
//     // run the loop without 
//     do {
//         // Get starting position and instructions from the user
//         printf("Enter robots starting position (x y): ");
//         int result = scanf("%d %d", &(robot.xpos), &(robot.ypos));

//         // checking if the argument is not 2 then it prints, other parts are just numerical range
//         if (result !=2 || robot.xpos < 0 || robot.xpos > 99 || robot.ypos < 0 || robot.ypos > 99) {
//             printf("x and y should be in the range of 0 and 99.\n");
//             clear_buffer();
//             continue; // skips rest of the loop and goes to second loop
//         }

//         printf("Enter m or t to either move or turn 90degrees followed by the  q when u wanna end it: ");
//       // Get instructions from the user
//         scanf("%s", instructions);
//         // for loop until the string ends
//         for (int i = 0; i < strlen(instructions); i++) {
//             //assign each char to endchar (so that we can use it to end the entire program later)
//             endChar = instructions[i];
//             // switch case  in case it is m it will be move and same for 
//             switch (instructions[i]) {
//             case 'm':
//                 move(&robot);
//                 break;
//             case 't':
//                 turn(&robot); 
//                 break;
//             }
//         }

//         printf("new position: (%d, %d) \n", robot.xpos, robot.ypos);
//         //while the char is q end it
//     } while (endChar != 'q');

//     return 0;
// }

// //recieving robot pointer and if it is N add 1 to Y, if it is E add one to X, if it is S substract 1 from Y, if it is W substract one from x  
// void move(ROBOT *robot) {
//     switch (robot->dir) {
//     case N:
//         robot->ypos++;
//         break;
//     case E:
//         robot->xpos++;
//         break;
//     case S:
//         robot->ypos--;
//         break;
//     case W:
//         robot->xpos--;
//         break;
//     }
// }
// // giving the robot to this function
// void turn(ROBOT* robot) {
//     // turning clockwise by changing direction, modula 4 is to make sure that it goes back to first enum
//     robot->dir = (robot->dir + 1) % 4;
// }

// //function for clearing the input buffer
// void clear_buffer(){
//     // this is for storing each character read from the input buffer
//     int c;
//     //loop until a newline character or EOF 
//     while ( (c = getchar()) != '\n' && c != EOF ) {
//         //keep reading characters and discarding them
//     }
// }
