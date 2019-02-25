// ----------------------------------------
//	PROJECT EULER PROBLEM 32
//		https://projecteuler.net/problem=32
// ----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAXNUM 10000

// Returns true if A, B, and C together are 1 - 9 pandigital
// A x B must = C
bool pandigital(int a, int b, int c);

int main(int argc, char *argv[]) {

    for (int i = 1; i < MAXNUM; i++) {
        for (int j = 0; j < MAXNUM; j++) {
            if (pandigital(i, j, i * j)) {
                printf("Found pandigital: %d x %d = %d\n", i, j, i * j);
            }
        }
    }
}


bool pandigital(int a, int b, int c) {
    uint8_t count[10] = {0};
    char strA[10];
    itoa(a, strA, 10);
    char strB[10];
    itoa(b, strB, 10);
    char strC[10];
    itoa(c, strC, 10);
    int lenA = strlen(strA);
    int lenB = strlen(strB);
    int lenC = strlen(strC);
    for (int i = 0; i < lenA; i++) {
        count[strA[i] - '0']++;
    }
    for (int i = 0; i < lenB; i++) {
        count[strB[i] - '0']++;
    }
    for (int i = 0; i < lenC; i++) {
        count[strC[i] - '0']++;
    }
    for (int i = 1; i < 10; i++) {
        if (count[i] != 1) {
            return false;
        }
    }
    return true;
}