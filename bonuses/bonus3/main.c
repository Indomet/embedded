/*
Write a C program to add two matrix (e.g.: 2x2) using pointers or arrays (max size should be 4x4). 
C program to input two matrix from user and find sum of both matrices using pointers.

Input matrix1: 
1 2 
4 5 

Input matrix2: 
9 8 
6 5 
Sum of both matrices:
10 10
10 10 
The input to the program should be provided in the following way:

Input the size: 2 2
Input elements of matrix 1: 1 2 4 5
Input elements of matrix 2: 9 8 6 5

The sum is: 
10 10 
10 10
*/

#include <stdio.h> // input output library, (printf, scanf)
#include <stdlib.h> //exit library

// this is to let program know that function exists after main
void addMatrix(int size1, int size2, int matrix[size1][size2]);
// this is to let program know that function exists after main
void sumMatrix(int size1, int size2, int matrix1[size1][size2], int matrix2[size1][size2], int sum[size1][size2]);

int main(int argc, char *argv[]){
    //size of row for matrix
    int size1;
    //size of column for matrix
    int size2;

    // this scans for 2 arguments and if arguments arenot exactly 2 then print invalid
    if(scanf("%d %d", &size1, &size2)!=2){
        printf("invalid\n");
        return 0;
    }
    // size of the argument is max 4 and min 2 if it is outside of this range print invalid
    if(size1>4|| size2>4 ||size1<=1|| size2<=1 ){
        printf("invalid");
        return 0;
    }

    // creating first matrix with the size of given row and column
    int matrix1[size1] [size2];
    // creating second matrix with the size of given row and column
    int matrix2[size1] [size2];
    // creating sum matrix with the size of given row and column
    int sum[size1] [size2];

    // we register input for the first matrix to matrix1 variable in this function
    addMatrix(size1,size2,matrix1);
    // we register input for the second matrix to matrix2 variable in this function
    addMatrix(size1,size2,matrix2);

    // adding all of the mattrices together
    sumMatrix(size1,size2,matrix1,matrix2,sum);
    //0 indicates that program has susccessfully executed
    return 0; 
}
// this function recieves size1(row) size2(column) and the matrix so that we can scan and update the given matrix
void addMatrix(int size1, int size2, int matrix[size1][size2]){
    // first loop is going through row
    for(int i= 0; i < size1; i++){
        //second loop is going through the column
        for(int j =0 ; j<size2; j++){ 
            // scanning input and to store in the matrix, 
            // if the scanf did not perform 1 argument then it means that it is not integer                                
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("invalid\n");
                // exit the program successfully
                exit(0);
            }
        }
    }
}

// this function recieves size1(row) size2(column), both of the matrices and sum matrix so that we can do addition
void sumMatrix(int size1, int size2, int matrix1[size1][size2], int matrix2[size1][size2], int sum[size1][size2]){
    printf("The sum is:\n");
    // first loop is going through row
    for(int i =0; i< size1; i++ ){
        //second loop is going through the column
        for(int j =0; j< size2; j++){
            // adding each matrix value to each other and saving to sum
            sum[i] [j] = matrix1[i] [j] + matrix2[i] [j];
            printf("%d " , sum[i] [j]);
        }
        printf("\n");
    }
}