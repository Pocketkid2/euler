// ----------------------------------------
//	PROJECT EULER PROBLEM 4
//		https://projecteuler.net/problem=4
// ----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DIGITS 6	// Because 3 digits times 3 digits will never be more than 6

// Int-To-String (automatically reverses number)
char *itos(int n) {
	// +1 for null char
	char *str = malloc(sizeof(char) * (DIGITS + 1));
	// Index to record digits
	int i = 0;
	// While there is a number part left
	while (n > 0) {
		// Store the ones-place digit
		str[i] = (n % 10) + '0';
		// Remove the ones-place
		n /= 10;
		// Move to next index
		i++;
	}
	// Terminate string and return
	str[i] = '\0';
	return str;
}

// String-To-Int (frees memory allocated by itos())
int stoi(char *str) {
	// Create number and index
	int n = 0, i = 0;
	// While we have characters left
	while (str[i] != '\0') {
		if (isdigit(str[i])) {
			// Add the digit's value and move on
			n *= 10;
			n += (str[i] - '0');
			i++;
		}
	}
	// Free the block and return number
	free(str);
	return n;
}

int main(int argc, char *argv[]) {
	int max = 0;
	// Loop through all two-permutations of 3 digit numbers
	for (int i = 100; i < 1000; i++) {
		for (int j = 100; j < 1000; j++) {
			// Find the product and it's reverse
			int a = i * j;
			int b = stoi(itos(a));
			// If they match and it's bigger than the current palindrome
			if (a == b && a > max) {
				max = a;
			}
		}
	}
	// We found it
	printf("Palindrome is %d\n", max);
}
