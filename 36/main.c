// ----------------------------------------
//	PROJECT EULER PROBLEM 36
//		https://projecteuler.net/problem=36
// ----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAXNUM 1000000
#define STRLEN 25

// Checks whether integer i is a palindrome in base b (base must be positive)
bool palindrome(int i, uint8_t b);

int main(int argc, char *argv[]) {

    uint64_t sum = 0;

    for (int i = 1; i < MAXNUM; i++) {
        if (palindrome(i, 2) && palindrome(i, 10)) {
            sum += i;
            printf("Adding number %d\n", i);
        }
    }

    printf("Sum = %" PRIu64 "\n", sum);
}

bool palindrome(int i, uint8_t b)
{
    char string[STRLEN];

    itoa(i, string, (int)b);

    // Index G starts at the first char, H at the last
    int g = 0;
    int h = strlen(string) - 1;

    // Move A and B together, and if at any point their chars don't match then it's not a palindrome
    while (g < h) {
        if (string[g] != string[h]) {
            return false;
        }
        g++;
        h--;
    }

    return true;
}
