#include <stdio.h> // included stdio for printing
#include <string.h> // included for strlen
int main(int argc, char *argv[]){
    //get the binary number
    char binaryString[256];
    if(argc == 2){
        strcpy(binaryString,argv[1]);
    }
    else{
    //get stdin and assign it to inpujt
    fgets(binaryString, 256, stdin);
    //assign the new line char index to 0 which replaces that char to \0 to remove it
    binaryString[strcspn(binaryString, "\n")] = 0;
    }
    if(strlen(binaryString) % 4 != 0){
        printf("Your input is not divisible by 4");
        return 2;
    }
    for(int i = 0; i < strlen(binaryString); i++){
        if((binaryString[i] != '0' && binaryString[i] != '1') ){
            printf("Your input isnt only 0s and 1s");
            return 2;
        }
    }

    // Im getting the length of character to be able loop through it
    int length = strlen(binaryString);
    // this is to count every 4 loop in the if statement
    int counter =0;
    // total number after counting the last 4 binary
    int sum = 0;
    // multiplier is is gonna be divided by 2 in each loop 
    int multiplier = 8;
    // for loop is from left to right 
    for(int i = 0; i<= length-1; i++){
        // im turning binarystring into an int
        int binary = binaryString[i] -'0';
        // im  multiplying by 8 in the first loop then 4, 2and 1 in the other loops 
        sum += multiplier * binary;
        //then in the other loops it is 4, 2and 1 
        multiplier = multiplier/2;
        // incrementing the counter 
        counter++;
        // when the counter hits 4  print the hexadecimal
        if (counter == 4){
            //if u dont want the leading 0s
            /*if(sum != 0){
            }*/
            printf("%X", sum);

            // reset the sum so that next 4 characters can be added
            sum=0;
            // reset the counter for next 4 characters
            counter = 0;
            // reset the multiplier to 8 for the next 4 characters 
            multiplier=8;
        }
    }
    return 0;
}
