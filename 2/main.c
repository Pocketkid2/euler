// ----------------------------------------
//	PROJECT EULER PROBLEM 2
//		https://projecteuler.net/problem=2
// ----------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

#define MAX_FIB 4000000

unsigned int next_fib() {
	static int f2 = 0;	// Holds the F(n-2) default=0
	static int f1 = 1;	// Holds the F(n-1) default=1
	static int f = 1;	// Holds the F(n)	default=1

	// Generate next F value
	f2 = f1;
	f1 = f;
	f = f2 + f1;

	// Return the generated value
	return f;
}

int main(int argc, char *argv[]) {
	int sum = 0;
	// Call next_fib until the result is greater than 4 million
	for (int f = next_fib(); f < MAX_FIB; f = next_fib()) {
		if (f % 2 == 0) {
			sum += f;
		}
	}
	printf("Sum = %d\n", sum);
}
