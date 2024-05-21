#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAXNUMBER 50
#define MAXGUESS 5

void getRandom(int *num);
void playGame(int numToGuess, FILE *file);
int main()
{
    FILE *file;
    file=fopen("file.txt","a");
    if(file==NULL){
        return 1;
    }
    
    int num;
    getRandom(&num);
    // printf("THE NUMBERRR %d \n", num);
    // fprintf(file,"THE NUMBERRR %d \n", num ) ;  
    char name[20];
    
    printf("the max number to guess is %d\n",MAXNUMBER);
    fprintf(file,"GAME: the max number to guess is %d\n",MAXNUMBER ) ; 
    printf("enter ur name\n");
    fprintf(file,"GAME: enter ur name\n") ; 
    scanf("%19s", name);   
    fprintf(file,"PLAYER: %s\n", name) ;
    // printf("%s", name);
    playGame(num, file);
    fprintf(file,"\n") ;
    fclose(file);
    return 0;
}

void getRandom(int *num){
    srand(time(NULL));
    
    *num = rand() % MAXNUMBER+1;
    
}
void playGame(int numToGuess, FILE *file){

    printf("enter a number to guess(enter -1 to forfeith)\n");
    fprintf(file,"GAME:enter a number to guess(enter -1 to forfeith)\n" ) ; 
    int num;
    int tries=0;
    while(tries < MAXGUESS){
        scanf("%d", &num);
        fprintf(file,"PLAYER: %d\n",num ) ; 
        if(num==-1){
            printf("you gave up ;(");
            fprintf(file,"GAME: you gave up ;(" ) ; 
            return;
        }
        tries++;
        if(num == numToGuess){
            printf("u WON\n");
            fprintf(file,"GAME: u WON\n" ) ; 
            return;
        }else if(tries==MAXGUESS){
            printf("you lost\n");
            fprintf(file,"GAME: you lost\n" ) ; 
            return; 
        }else if(num< numToGuess){
            printf("too low\n");
            fprintf(file,"GAME: too low\n" ) ; 
        }else if(num>numToGuess){
            printf("too high\n");
             fprintf(file,"GAME: too high\n" ) ; 
        }
    }

}

