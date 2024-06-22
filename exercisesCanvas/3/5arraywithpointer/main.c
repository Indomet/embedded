#include <stdio.h> //standard input/output library
#include <stdlib.h> //standard library
#include <time.h> //time library
#define MAX 10 //size of the array
#define MAX_NUM 100 //max number for random number generation
//letting the program know that there is function after main
void random_array(int* array_ptr);

int main(int argc, char* argv[]) {
    //allocating memory for the array
    int* array = malloc(sizeof(int) * MAX);
    //checking if the memory allocation was successful
    random_array(array);
    printf("The value of the address of the array (pointer) is: %p\n", array);
    printf("First integer in the array is (array[0]): %d\n", *array);
    printf("The last integer in the array is: %d\n", array[MAX - 1]);
    printf("The size of an integer (number of bytes) is: %d\n", sizeof(*array));
    printf("The size of the whole array in bytes is: %d\n", sizeof(*array) * MAX);
    //looping through the array and printing out the values
    for (int i = 0; i < MAX; i++) {
        printf("Integer: %d,  2 * Integer: %d\n", *array, *array * 2);
        //incrementing the pointer to point to the next integer in the array
        array++;
    }
    //freeing the memory allocated for the array
    free(array);
}

void random_array(int* array_ptr) {
    //seeding the random number generator
    srand(time(NULL));
    //looping through the array and assigning random numbers to the array
    for (int i = 0; i < MAX; i++) {
        //generating a random number
        int nr = rand() % MAX_NUM;
        //assigning the random number to the array
        *array_ptr = nr;
        //incrementing the pointer to point to the next integer in the array
        array_ptr++;
    }
}