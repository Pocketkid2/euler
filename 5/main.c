// ----------------------------------------
//	PROJECT EULER PROBLEM 5
//		https://projecteuler.net/problem=5
// ----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_DIV 20

// Compute the Greatest Common Divisor of two numbers
unsigned int gcd(unsigned int a, unsigned int b) {
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

// Compute the Least Common Multiple of two numbers
unsigned int lcm(unsigned int a, unsigned int b) {
	if (a > b) {
		return (a / gcd(a, b)) * b;
	} else {
		return (b / gcd(a, b)) * a;
	}
}

int main(int argc, char *argv[]) {
	int min = 1;
	// Loop through 1...19
	for (int i = 1; i < MAX_DIV; i++) {
		// Find the LCM of i and the next number, and the previous LCM
		int l = lcm(lcm(i, i + 1), min);
		if (l > min) {
			min = l;
		}
	}
	// We found the LCM of all of them
	printf("Minimum common factor = %d\n", min);
}
