#include <stdio.h>
void armStrong(int num){
    int lastDecimal;
    int sum;
    while(num !=0){
        // gets last number
        lastDecimal= num%10;
        //takes cube
        sum+= lastDecimal*lastDecimal*lastDecimal;
        //goes to the next digit after last one
        num= num/10;
    }
    printf("%d", sum);
}
void perfectNumber(int num){
    int sum;
    for(int i = 1; i<num;i++){
        if(num%i==0){
            sum+= i;
        }
    }
    printf("%d", sum);
}


int main(int argc, char *argv[])
{
    int num = 153; 
// armStrong(num);
perfectNumber(28);
// printf("%d\n", num);
    return 0;
    
}
//153 armStrong
// 28 perfect
