/*
The elevator controller uses one byte (8 bits) to store the status of the elevator.

 

The values/meaning of the bits of the byte are:

 

Name           Bits       Info   
engine_on      1          Is engine on or off (the elevator moves or not). This is bit no 7 (MSB)
floor_pos      3          Which floor number the elevator should go to (0-7)  
door_pos       2          If the door is open or closed  
brake1         1          Normal brakes
brake2         1          Emergency brakes
 

We should store them in a byte like this:

[engine_on]  [floor_pos]   [door_pos]    [brake1]   [brake2]          

 1 bit       3 bits         2 bits        1 bit      1 bit
 

(8 bits in total)

 

Write a program which takes 5 arguments (different number of arguments should result in an error message). 
The arguments should correspond to the values/variables above. The program should also be able to print error 
message if the bit combination is invalid. 

Example for a start of the program from command line:

main   1 7 1 1 0          
The above should be treated as:

Name                Value  
----------------------------
engine_on            1      
floor_pos            7
door_pos             1
brake1               1
brake2               0

and the output should be
0xF6
*/

#include <stdio.h> // print library
#include <stdlib.h>// atoi and exit library
// let the program know tat there is function after main
unsigned char bitpacker(int engineOn, int floorPos, int doorPos, int brake1, int brake2);

int main(int argc, char *argv[]){
    //check if the number of arguments is correct
    if(argc!=6){
        printf("invalid\n");
        //end the program successfully
        return 0;
    }
    //convert the arguments to integers
    int engineOn = atoi(argv[1]);
    int floorPos =atoi(argv[2]);
    int doorPos = atoi(argv[3]);
    int brake1=atoi(argv[4]);
    int brake2=atoi(argv[5]);
    
    // returned packed value to print
    unsigned char packed= bitpacker(engineOn,floorPos,doorPos,brake1,brake2);
    printf("0x%X\n", packed);

    //return 0 to show that program executed successflly
    return 0;
}

unsigned char bitpacker(int engineOn, int floorPos, int doorPos, int brake1, int brake2) {
    // make sure values are within the specified ranges
    if (engineOn < 0 || engineOn > 1 || floorPos < 0 || floorPos > 7 || doorPos < 0 || doorPos > 2 ||
        brake1 < 0 || brake1 > 1 || brake2 < 0 || brake2 > 1) {
        printf("invalid\n");
        //end the program successfully
        return 0;
    }

    // pack values into a byte
    unsigned char packedByte = 0;

    // |= sets all the values that are on(1) in the position of where it should be
    // for example for engine it is the most significant one if it is on it ill directly set it to on
    packedByte |=(engineOn & 0b1) << 7; // or packedByte |= (engine_on & 0b10000000);

    // shift the floorPos 4 bits to the left and set it to the packedByte
    packedByte |=(floorPos & 0b111) << 4;
    
    //shift the doorPos 2 bits to the left and set it 
    packedByte |= (doorPos & 0b11) << 2;
    //shift the brake1 1 bit to the left and set it
    packedByte |=(brake1 & 0b1) << 1;
    //set the brake2
    packedByte |= brake2 & 0b1;

    //return the packedbyte
    return packedByte;
}