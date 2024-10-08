#include <stdio.h> //included this libray for printing 
#include <stdlib.h> // included this library for getting random numbers
#include <time.h> //included this library to get 
#include <ctype.h> //included this for tolower method it makes chars lowercase

#define MAX_RANGE 100 //define the max range for the number guess game
#define MIN_RANGE 1 //define the min range for the number guess game
#define MAX_NUMBER 5 // this is the max number that the player can guess

// this is needed so that program knows which methods exist after main
int randomGenerator(int max, int min); 
// this is needed so that program knows which methods exist after main
void rePlay(); 
// this is needed so that program knows which methods exist after main
void playGame(); 

// argc counts the arguments and argv is the argument itself (not needed for this exercise)
int main(int argc, char *argv[]){ 
    // this executes the playgame method
    playGame();
    // returning 0 means that program executed successfully
    return 0;
}

void playGame(){
    // this generates random number between the defined range
    int randomNumber = randomGenerator(MAX_RANGE,MIN_RANGE);
    // this is the number user puts in to guess during execution
    int guessedNumber; 
    // this is to count how many guesses have been made
    int guessCounter = 0;
    printf("Guess the number:\n");
    // printf("%d\n", randomNumber);

    // this is a loop for when the number given by the user is wrong and  the gueescounter does not exceed max number
    while(guessedNumber != randomNumber && guessCounter < MAX_NUMBER){
    // we use do to run the loop without checking first so that the user can enter a number before we chack if it is in range
    do {
        // we scan the number given by the user
        scanf("%d", &guessedNumber);
        //this is to check if the number given is in the range
        if (guessedNumber < MIN_RANGE || guessedNumber > MAX_RANGE) {
            printf("Invalid number, a number between %d and %d.\n", MIN_RANGE, MAX_RANGE);
            //clear the input buffer in case of non integer input
            while (getchar() != '\n'); // this is to prevent crash when non integer value is entered 
        }
        //in the second loop we check if the newly entered number is in the range if not the loop continues
    }while (guessedNumber < MIN_RANGE || guessedNumber > MAX_RANGE); 
    //inform the user if the number entered is lower than the random number
    if(guessedNumber < randomNumber){
        printf("Your guess is too low\n");
    }
    //inform the user if the number entered is higher than the random number
    else if(guessedNumber > randomNumber){
        printf("Your guess is too high\n");
    }
        // in every single loop count the trials
        guessCounter++;
    }
    //if the guessed number is same as the random number you win otherwise loose
    if(guessedNumber == randomNumber){
        printf("You have guessed %d times and your guess is correct\n",guessCounter);
    }else{
        printf("You have guessed %d times which exceeded the max try (%d) YOU LOST! Correct Answer: %d\n",guessCounter, MAX_NUMBER, randomNumber );
    }
    // this is a function that asks u if u want to play again
    rePlay();
}

void rePlay(){
    printf("Do you want to play again? Press q to quit or anything else to play again\n");
    // this is to wait until user inputs something in the chat
    while (getchar()== 0){}
    // if the input is not q restart the game otherwise stop the game
    if(tolower(getchar()) != 'q'){
        playGame();
    } 
}
// this function takes in ranges from the playGame Function
int randomGenerator(int max, int min){
    // this is to give the rand() function a number that is generated by the time, which will make the rand() function give random numbers
    srand(time(NULL));
     // return andom number between 1 and 100, i added + 1 since if the random number is 100 the result will be 0
    return rand() % max + min; // max =100 and min = 1 according to question
}
//benim