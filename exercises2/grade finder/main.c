/******************************************************************************
Write a C program to input marks of five subjects Physics, Chemistry, Biology, Mathematics and
Computer, calculate percentage and grade according to given conditions:
If percentage >= 90% : Grade A
If percentage >= 80% : Grade B
If percentage >= 70% : Grade C
If percentage >= 60% : Grade D
If percentage >= 40% : Grade E
If percentage < 40% : Grade F
Example
Input
Input marks of five subjects: 95
95
97
98
90
Output
Percentage = 95.00
Grade A
*******************************************************************************/
#include <stdio.h>

int main()
{   
    int treshold[]= {0,40,60,70,80,90};
    int physics;
    int chemistry;
    int biology;
    int math;
    int computer;
    scanf("%d", &physics);
    scanf("%d", &chemistry);
    scanf("%d", &biology);
    scanf("%d", &math);
    scanf("%d", &computer);
    
    float percentage =(physics+chemistry+biology+math+ computer)/5;
    printf("%2.2f", percentage);
    for(int i = 0; i<6; i++){
        if(percentage >= treshold[i] && percentage<treshold[i+1]){
            switch (i){
            case 0:
                printf("F");
                break;
            case 1: 
                printf("E");
                break;
                
            case 2: 
                printf("D");
                break;
            case 3: 
                printf("C");
                break;
            case 4: 
                printf("B");
                break;
            case 5: 
                printf("A");
                break;
            }
        }
    }

    
    return 0;
}
