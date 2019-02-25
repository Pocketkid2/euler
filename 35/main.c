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

    // Test by printing all primes
    for (int i = 2; i < SIZE; i++) {
        if (prime[i]) {
            printf("%d\n", i);
        }
    }

}
