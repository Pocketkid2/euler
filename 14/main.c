// ----------------------------------------
//	PROJECT EULER PROBLEM 14
//		https://projecteuler.net/problem=14
// ----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

void seq(uint64_t *count, uint64_t start)
{
	(*count)++;
	if (start == 1) {
		return;
	} else if (start % 2) {
		// IF ODD
		seq(count, (3 * start) + 1);
	} else {
		// IF EVEN
		seq(count, start / 2);
	}
}

int main(int argc, char *argv[]) {

	uint64_t count = 0;
	uint64_t max = 0;
	int maxStart = 0;


	for (int i = 1; i <= 1000000; i++) {
		seq(&count, i);
		printf("Traveled sequence starting with %d, chain length: %" PRIu64 "\n", i, count);
		if (count > max) {
			max = count;
			maxStart = i;
		}
		count = 0;
	}

	printf("Maximum chain starts at %d\n", maxStart);
}
