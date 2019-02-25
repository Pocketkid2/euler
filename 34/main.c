// ----------------------------------------
//	PROJECT EULER PROBLEM 34
//		https://projecteuler.net/problem=34
// ----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAXNUM 1000000000
#define STRLEN 10

int factorial[10] = {
    1,
    1,
    2,
    6,
    24,
    120,
    720,
    5040,
    40320,
    362880
};

bool curious(int n);

int main(int argc, char *argv[]) {
    for (int i = 3; i < MAXNUM; i++) {
        if (curious(i)) {
            printf("Found curious number: %d\n", i);
        }
    }
}

bool curious(int n) {
    char string[STRLEN];
    itoa(n, string, 10);
    int sum = 0;
    for (int i = 0; i < strlen(string); i++) {
        sum += factorial[string[i] - '0'];
    }
    return sum == n;
}
