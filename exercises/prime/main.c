#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void printBinary(int *num, int num_bits){
    // char hex[];
    // sscanf(hex,"%c", &hex);
    // printf("hellu %s", hex);
    
    printf("0b");
    for(int i=num_bits; i>=0; i--){
        printf("%d", (*num>>i)&1);
    }
}
void toggleBits(int *num, char *toggle, int index){
    index = index-1;
    if(index >= 0 && index < 32&& strcmp(toggle, "set")==0){
        printf("0x%X == ",*num |= (1<<index));
        // printf("%d",*num |= (1<<index));
    }else if(index >= 0 && index < 32&& strcmp(toggle, "unset")==0){
        printf("0x%X == ",*num &= ~(1<<index));
    }
    
      

}


int hexaToDecimal(char *hex) {
    int decimal;
    sscanf(hex, "%x", &decimal); 
    // printf("%d\n",decimal);
    return decimal;
}

int main(int argc, char *argv[])
{
   char *firstArg =argv[1];
    // for(int i=0; i<= strlen(firstArg); i++){
    // if(firstArg[i] != 'A' && firstArg[i] != 'B' && firstArg[i] != 'C' && firstArg[i] != 'D' && firstArg[i] != 'E' && firstArg[i] != 'F'){
    //     printf("First argument should be like in the example 0xFF00");
    //     return 0;
    // }
    // }
    
    
    char *secondArg=argv[2];

    

  
    int thirdInput = atoi(argv[3]);
    if(strcmp(secondArg, "set")!=0 && strcmp(secondArg, "unset")!=0){
    printf("Second argument should be either set or unset");
        return 0;
    }
    int num =hexaToDecimal(firstArg);
    int num_bits =floor(log2(num)+1);
    if(thirdInput <= 0|| thirdInput> num_bits){
        printf("third input cant be less than or equal to 0  or more than number of bits(%d)", num_bits);
        return 0;
    }
    toggleBits(&num, secondArg, thirdInput);
 
    printBinary(&num, num_bits);
    return 0;
}


