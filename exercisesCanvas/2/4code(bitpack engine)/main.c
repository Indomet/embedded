
#include <stdio.h> // print library
#include <stdlib.h> // atoi and exit library
// let the program know tat there is function after main

typedef unsigned char byte;
byte bitpacker(int engineOn, int gearPos, int keyPos, int brake1, int brake2);

int main(int argc, char* argv[]) {
    // check if the number of arguments is correct
    if (argc != 6) {
        printf("Enter exactly 5 arguments");
        // exit if not corret
        exit(1);
    }
    // convert the arguments to integers
    int engineOn = atoi(argv[1]);
    // convert the arguments to integers
    int gearPos = atoi(argv[2]);
    // convert the arguments to integers
    int keyPos = atoi(argv[3]);
    // convert the arguments to integers
    int brake1 = atoi(argv[4]);
    // convert the arguments to integers
    int brake2 = atoi(argv[5]);

    // returned packed value to print
    byte packed = bitpacker(engineOn, gearPos, keyPos, brake1, brake2);
    printf("%X\n", packed);
    // printf("%d\n", packed);

    // return 0 to show that program executed successflly
    return 0;
}
// function to pack the values into a byte
byte bitpacker(int engineOn, int gearPos, int keyPos, int brake1, int brake2) {
    // make sure values are within the specified ranges
    if (engineOn < 0 || engineOn > 1 || gearPos < 0 || gearPos > 7 || keyPos < 0 || keyPos > 2 || brake1 < 0 || brake1 > 1 || brake2 < 0 || brake2 > 1) {
        printf("invalid.\n");
        // exit if not corret
        exit(1);
    }

    // pack values into a byte
    byte packedByte = 0;

    // |= sets all the values that are on(1) in the position of where it should be
    // for example if engine is on it will shift the 1, 7 positions to the left making it 10000000 whích then
    // will be compared with 10000000 and will reuslt in turning the packed bytes first bit on
    packedByte |= (engineOn & 0b1) << 7;

    // shift the gearPos 4 bits to the left and set it to the packedByte
    packedByte |= (gearPos & 0b111) << 4;

    // shift the keyPos 2 bits to the left and set it
    packedByte |= (keyPos & 0b11) << 2;
    // shift the brake1 1 bit to the left and set it
    packedByte |= (brake1 & 0b1) << 1;
    // set the brake2
    packedByte |= brake2 & 0b1;

    // return the packedbyte
    return packedByte;
}