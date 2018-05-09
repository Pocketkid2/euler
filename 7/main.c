// ----------------------------------------
//	PROJECT EULER PROBLEM 7
//		https://projecteuler.net/problem=7
// ----------------------------------------

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
	int s = sqrt(n);
	// Iterate through possible factors 2...sqrt(n)
	for (int i = 2; i <= s; i++) {
		// If any of them are divisible, it's not prime
		if (n % i == 0) {
			return false;
		}
	}
	// If we get down here, then the number must be prime
	return true;
}

int nthPrime(int n) {
	int p, c;	// Possible prime and current counter
	// Start at prime 2 and continue until prime count reaches n
	for (p = 2, c = 0; c < n; p++) {
		if (isPrime(p)) {
			c++;
		}
	}
	// Return the one before possible prime because of increments
	return p - 1;
}

int main(int argc, char *argv[]) {
	printf("The 10001st prime is %d\n", nthPrime(10001));
}
