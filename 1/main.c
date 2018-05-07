// ----------------------------------------
//	PROJECT EULER PROBLEM 1
//		https://projecteuler.net/problem=1
// ----------------------------------------

#include <stdio.h>

int main(int argc, char *argv[]) {
	int sum = 0;
	// Loop from 1...999
	for (int i = 1; i < 1000; i++) {
		// If divisible by 3 or 5
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	printf("Sum of all multiples = %d\n", sum);
}
