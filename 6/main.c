// ----------------------------------------
//	PROJECT EULER PROBLEM 6
//		https://projecteuler.net/problem=6
// ----------------------------------------

#include <stdio.h>

#define NUMBER 100

int main(int argc, char *argv[]) {
	unsigned int sumOfSquares = 0;
	for (int i = 1; i <= NUMBER; i++) {
		sumOfSquares += i * i;
	}

	unsigned int squareOfSum = 0;
	for (int i = 1; i <= NUMBER; i++) {
		squareOfSum += i;
	}
	squareOfSum *= squareOfSum;

	printf("Difference: %d\n", squareOfSum - sumOfSquares);
}
