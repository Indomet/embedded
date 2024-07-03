#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
    // Check if the number is less than or equal to 1
    if (num <= 1) {
        return 0; // If so, it's not prime
    }
    // Check divisibility of the number from 2 up to the square root of the number
    for (int i = 2; i * i <= num; i++) {
        // If the number is divisible by any other number, it's not prime
        if (num % i == 0) {
            return 0;
        }
    }
    // If the number passes all tests, it's prime
    return 1;
}

// Function to find the nth prime number
int findNthPrime(int n) {
    int count = 0; // Initialize a counter for prime numbers found
    int num = 2; // Start with the first prime number

    // Loop until the desired number of prime numbers are found
    while (count < n) {
        // Check if the current number is prime
        if (isPrime(num)) {
            count++; // If so, increment the count of prime numbers found
        }
        // If we have found the desired number of primes, break the loop
        if (count == n) {
            break;
        }
        num++; // Move to the next number to check
    }

    // Return the nth prime number
    return num;
}

int main() {
    int index;
    // Prompt the user to enter the index of the prime number they want to find
    printf("Enter the index of the prime number you want to find: ");
    // Read the index from the user input
    scanf("%d", &index);

    // Check if the index is valid (greater than 0)
    if (index <= 0) {
        // If not, print an error message
        printf("Invalid index\n");
    } else {
        // If the index is valid, find the prime number at that index
        int prime = findNthPrime(index);
        // Print the prime number at the given index
        printf("The prime number at index %d is: %d\n", index, prime);
    }

    return 0;
}
