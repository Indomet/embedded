#include <stdio.h> //input output library
#include <stdlib.h> // exit library
#include <string.h> // length library

void unpackBits(unsigned char packedByte) {

    // extractingg each bit from a byte by shifting the byte by to position they were taken from
    // thenusing and operator to switch it back to original hexadecimal position
    int engine_on = (packedByte >> 7) & 0b1;
    // this ternary operation is to check if the converted value is in the range of our car
    // if not print invalid and exit
    engine_on > 1 ? printf("invalid\n"), exit(1) : engine_on;

    // extractingg each bit from a byte by shifting the byte by to position they were taken from
    // thenusing and operator to switch it back to original hexadecimal position
    int gear_pos = (packedByte >> 4) & 0b111;
    // this ternary operation is to check if the converted value is in the range of our car
    // if not print invalid and exit
    gear_pos > 7 ? printf("invalid\n"), exit(1) : gear_pos;

    // extractingg each bit from a byte by shifting the byte by to position they were taken from
    // thenusing and operator to switch it back to original hexadecimal position
    int key_pos = (packedByte >> 2) & 0b11;
    // this ternary operation is to check if the converted value is in the range of our car
    // if not print invalid and exit
    key_pos > 2 ? printf("invalid\n"), exit(1) : key_pos;

    // extractingg each bit from a byte by shifting the byte by to position they were taken from
    // thenusing and operator to switch it back to original hexadecimal position
    int brake1 = (packedByte >> 1) & 0b1;
    // this ternary operation is to check if the converted value is in the range of our car
    // if not print invalid and exit
    brake1 > 1 ? printf("invalid\n"), exit(1) : brake1;

    // extractingg each bit from a byte by shifting the byte by to position they were taken from
    // thenusing and operator to switch it back to original hexadecimal position
    int brake2 = packedByte & 0b1;
    // this ternary operation is to check if the converted value is in the range of our car
    // if not print invalid and exit
    brake2 > 1 ? printf("invalid\n"), exit(1) : brake2;

    // printing the values
    printf("Name         Value\n");
    printf("-----------------------------\n");
    printf("engine_on    %d\n", engine_on);
    printf("gear_pos     %d\n", gear_pos);
    printf("key_pos      %d\n", key_pos);
    printf("brake1       %d\n", brake1);
    printf("brake2       %d\n", brake2);
}

int main(int argc, char* argv[]) {
    // checking the number of arguments to see if it is correct
    if (argc != 2) {
        printf("invalid\n");
        return 1;
    }

    // if the length of the argument is bigger than 2 then it means that it is more than bits we can use
    if (strlen(argv[1]) > 2) {
        printf("invalid\n");
        return 1;
    }

    // Parse the input hexadecimal value
    unsigned char packedByte;
    // x is the format for hexadecimal and it is used to interpret the argument as hexadecimal
    // and then the value us saved iside char
    // sscanf reads the data from first field(which is argument) and formats it according to second parameter
    // hhx converts input to unsigned char, while x converts to unsigned int.
    sscanf(argv[1], "%hhX", &packedByte);

    // send it to unpackbits to decrypt
    unpackBits(packedByte);

    // return 0 to indicate that the program is successfully exited
    return 0;
}
