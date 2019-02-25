// ----------------------------------------
//	PROJECT EULER PROBLEM 35
//		https://projecteuler.net/problem=35
// ----------------------------------------e

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define SIZE 1000000
#define SQRT 1000   // <- Pre-calculated square root of the size (for simplicity and efficiency)
#define STRLEN 10

// Checks if the prime given is a circular number in base 10
bool circular(int i, bool prime[SIZE]);

// Rotates the given string in-place by 1
void rotate(char *str);

int main(int argc, char *argv[]) {

    // Initialize prime array
    bool prime[SIZE];
    for (int i = 2; i < SIZE; i++) {
        prime[i] = true;
    }

    // Mark off all non-primes
    for (int i = 2; i <= SQRT; i++) {
        if (prime[i]) {
            for (int j = i * i; j < SIZE; j += i) {
                prime[j] = false;
            }
        }
    }

    int count = 0;

    // Print all circular primes
    for (int i = 2; i < SIZE; i++) {
        if (prime[i]) {
            if (circular(i, prime)) {
                printf("Found circular prime: %d\n", i);
                count++;
            }
        }
    }

    printf("Number of circular primes below %d: %d\n", SIZE, count);

}

// Assumes that i is already known to be a prime
bool circular(int i, bool prime[SIZE]) {
    char string[STRLEN];
    char modify[STRLEN];
    itoa(i, string, 10);
    strcpy(modify, string);
    rotate(modify);
    while (strcmp(string, modify)) {
        if (!prime[atoi(modify)]) {
            return false;
        }
        rotate(modify);

    }
    return true;
}

// Rotate the given string by 1 to the left (i.e. grab first char and move to end)
void rotate(char *str) {
    char first = *str;
    int len = strlen(str);
    for (int i = 0; i < (len - 1); i++) {
        str[i] = str[i+1];
    }
    str[len - 1] = first;
}