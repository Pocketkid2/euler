// ----------------------------------------
//	PROJECT EULER PROBLEM 9
//		https://projecteuler.net/problem=9
// ----------------------------------------

#include <stdio.h>

// These are the minimum values needed to find the specific pythagorean triple
#define MAX_N 5
#define MAX_M 20
#define MAX_K 1

int main(int argc, char *argv[]) {
	// Loop through a TON of values of N, M, and K
	for (int n = 1; n <= MAX_N; n++) {
		for (int m = n + 1; m <= MAX_M; m++) {
			for (int k = 1; k <= MAX_K; k++) {
				// Generate the triple with N, M, and K
				int a = (m * m) - (n * n);
				int b = 2 * m * n;
				int c = (m * m) + (n * n);
				// Check if the triple is valid
				if (a + b + c == 1000) {
					printf("Triple: %d, %d, %d = %d (made with n = %d, m = %d, k = %d)\n", a, b, c, a*b*c, n, m, k);
				}
			}
		}
	}
}
