/*
Write a program for calculating and storing Fobonacci sequences. 

The program should take one argument - the Fibonacci number - and then generate the correct Fibonacci sequence 

The program should store all Fibonacci numbers as a linked list and use the elements in the list to calculate the numbers.
 For example when calculating the fourth number (3), the program should take the third number (2) and the second number (1) 
 from the list. Recursion is NOT allowed. 

The program should write out the number, for example:

Input: main.exe 5

Output: 3
*/

#include <stdio.h> // printf, scanf library
#include <stdlib.h> // malloc library

// struct definitiones of the nodes
typedef struct q {
    int number;
    struct q* next;
    struct q* prev;
} NODE;

//letting the program know that fuction exists after main
NODE* createFibonacci(int number);

int main(int argc, char *argv[]){
    // turn tha argument into an integer
    int number = atoi(argv[1]);
    // call the function to create the fibonacci sequence
    NODE *ptr = createFibonacci(number);
    //dereference the pointer 
    printf("%d",ptr->number);
    //return 0 to exit program successfully

    //free the memory untill the pointer is null
    while(ptr != NULL){
        //set the temp to the pointer
        NODE* temp = ptr;
        //set the pointer to the previous
        ptr = ptr->prev;
        //free the temp in each loop
        free(temp);
    }
    return 0;
}


//function to create the fibonacci sequence
NODE* createFibonacci(int number){
    //allocate memory for the first node
    NODE* head = malloc(sizeof(NODE));
    //set the first node to 0
    head->number = 0;
    //set the next to null
    head->next = NULL;
    //set the previous to null
    head->prev = NULL;
    //set the current to the head
    NODE* current = head;
    //set the previous to the head
    NODE* previous = head;
    //loop through the number of nodes to create
    for(int i = 1; i < number; i++){
        //allocate memory for the newly created node
        NODE* newNode = malloc(sizeof(NODE));
        //this is base case if i is 1 then second index is 1
        if(i == 1) {
            //set the number to 1
            newNode->number = 1;
        } else {
            //set the newnode bymber to sum of the current and previous number
            newNode->number = current->number + previous->number;
        }
        //set the next to null
        newNode->next = NULL;
        //set the previous to the current
        newNode->prev = current;
        //set the current to the newnode
        current->next = newNode;
        //set the previous to the current
        previous = current;
        //set the current to the newnode
        current = newNode;
    }
    //return the current number of the linked list
    return current;
}