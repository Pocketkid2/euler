#include <stdio.h>

#define BUF_SIZE 302

// Adds the digits in A and B and stores the result in C
void add(char a[BUF_SIZE], char b[BUF_SIZE], char c[BUF_SIZE]) {

    int carry = 0;

    for (int i = BUF_SIZE - 1; i >= 0; i--) {
        int one = a[i];
        int two = b[i];

        int sum = one + two + carry;

        c[i] = sum % 10;
        carry = sum / 10;
    }
}

void copy(char a[BUF_SIZE], char b[BUF_SIZE], char c[BUF_SIZE]) {
    for (int i = 0; i < BUF_SIZE; i++) {
        a[i] = b[i] = c[i];
    }
}

void print(char a[BUF_SIZE]) {
    for (int i = 0; i < BUF_SIZE; i++) {
        printf("%c", a[i] + '0');
    }
    printf("\n\n");
}

int sum(char a[BUF_SIZE]) {
    int sum = 0;
    for (int i = 0; i < BUF_SIZE; i++) {
        if (a[i] > 0) {
            sum += a[i];
        }
    }
    return sum;
}

int main() {
    char addend_one[BUF_SIZE] = {0};
    char addend_two[BUF_SIZE] = {0};
    char result[BUF_SIZE] = {0};

    addend_one[BUF_SIZE - 1] = 1;
    addend_two[BUF_SIZE - 1] = 1;

    for (int i = 0; i < 1000; i++) {
        add(addend_one, addend_two, result);
        copy(addend_one, addend_two, result);
    }

    print(result);

    printf("Sum = %d\n\n", sum(result));

}