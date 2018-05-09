// -----------------------------------------
//	PROJECT EULER PROBLEM 10
//		https://projecteuler.net/problem=10
// -----------------------------------------

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include <inttypes.h>
#include <math.h>

#define SIEVE_SIZE 2000000

int main(int argc, char *argv[]) {
	bool sieve[SIEVE_SIZE];
	// Initialize the sieve
	for (int i = 0; i < SIEVE_SIZE; i++) {
		sieve[i] = true;
	}

	// Mark all non-primes
	int s = sqrt(SIEVE_SIZE);
	// From 2...sqrt(n)
	for (int i = 2; i <= s; i++) {
		// Mark all multiples of i starting at i^2
		if (sieve[i]) {
			for (int j = i * i; j < SIEVE_SIZE; j += i) {
				sieve[j] = false;
			}
		}
	}

	// Sum all primes
	uint64_t sum = 0;
	// Re-iterate and find all primes and add to sum
	for (uint64_t i = 2; i < SIEVE_SIZE; i++) {
		if (sieve[i]) {
			sum += i;
		}
	}
	printf("Sum: %" PRIu64 "\n", sum);
}
