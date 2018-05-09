// -----------------------------------------
//	PROJECT EULER PROBLEM 12
//		https://projecteuler.net/problem=12
// -----------------------------------------

#include <stdio.h>
#include <stdbool.h>

int factors(int n) {
	int f = 0;
	double s = sqrt(n);
	for (int i = 1; i < s; i++) {
		if (n % i == 0) {
			f++;
			if ((i * i) != n) {
				f++;
			}
		}

	}
	return f;
}

int nextTriangleNumber() {
	static int n = 1;
	static int x = 2;
	n += x++;
	return n;
}

int main(int argc, char *argv[]) {
	int t;
	while (factors((t = nextTriangleNumber())) <= 500 && t > 0);
	printf("Triangle number: %d\n", t);
}
