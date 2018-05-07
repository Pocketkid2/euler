// ----------------------------------------
//	PROJECT EULER PROBLEM 3
//		https://projecteuler.net/problem=3
// ----------------------------------------

#include <stdio.h>
#include <math.h>
#include <stdint.h>

#define NUMBER 600851475143

uint64_t getLargestFactor(uint64_t n) {
	// The current highest factor
	uint64_t f = 1;
	// The square root of N, a.k.a the stopping point
	uint64_t s = (uint64_t)floor(sqrt(n));
	// Loop through 2...sqrt(n) to check for factors
	for (int i = 2; i <= s; i++) {
		if (n % i == 0) {
			f = i;
		}
	}
	// At the end of the loop, the highest factor is inside f
	return f;
}

int main(int argc, char *argv[]) {
	uint64_t n = NUMBER;
	uint64_t f = 1;
	uint64_t s = (uint64_t)floor(sqrt(n));

	for (int i = 2; i <= s; i++) {
		// If i divides the number
		if (n % i == 0) {
			// Check if it's prime i.e. if it's highest factor is one
			if (getLargestFactor(i) == 1) {
				f = i;
			}
		}
	}

	// We now have the largest PRIME factor in f
	printf("Largest prime factor = %d\n", f);
}
