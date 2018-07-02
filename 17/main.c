#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *singleDigit(int n) {
    char *temp;
    char *str;
    switch (n) {
        case 0:
            temp = "zero";
            break;
        case 1:
            temp = "one";
            break;
        case 2:
            temp = "two";
            break;
        case 3:
            temp = "three";
            break;
        case 4:
            temp = "four";
            break;
        case 5:
            temp = "five";
            break;
        case 6:
            temp = "six";
            break;
        case 7:
            temp = "seven";
            break;
        case 8:
            temp = "eight";
            break;
        case 9:
            temp = "nine";
            break;
    }
    str = malloc(sizeof(char) * (strlen(temp) + 1));
    strcpy(str, temp);
    return str;
}

char *teenDigit(int n) {
    char *temp;
    char *str;
    switch (n) {
        case 10:
            temp = "ten";
            break;
        case 11:
            temp = "eleven";
            break;
        case 12:
            temp = "twelve";
            break;
        case 13:
            temp = "thirteen";
            break;
        case 14:
            temp = "fourteen";
            break;
        case 15:
            temp = "fifteen";
            break;
        case 16:
            temp = "sixteen";
            break;
        case 17:
            temp = "seventeen";
            break;
        case 18:
            temp = "eighteen";
            break;
        case 19:
            temp = "nineteen";
            break;
    }
    str = malloc(sizeof(char) * (strlen(temp) + 1));
    strcpy(str, temp);
    return str;
}

char *tensDigit(int n) {
    char *temp;
    char *str;
    switch (n) {
        case 2:
            temp = "twenty";
            break;
        case 3:
            temp = "thirty";
            break;
        case 4:
            temp = "forty";
            break;
        case 5:
            temp = "fifty";
            break;
        case 6:
            temp = "sixty";
            break;
        case 7:
            temp = "seventy";
            break;
        case 8:
            temp = "eighty";
            break;
        case 9:
            temp = "ninety";
            break;
    }
    str = malloc(sizeof(char) * (strlen(temp) + 1));
    strcpy(str, temp);
    return str;
}

char *subHundredParse(int n) {
    assert(n < 100);

    if (n >= 0 && n <= 9) {
        return singleDigit(n);
    }

    if (n >= 10 && n <= 19) {
        return teenDigit(n);
    }

    char *tens = tensDigit(n / 10);
    char *ones = singleDigit(n % 10);

    char *final;

    if (n % 10) {
        final = malloc(sizeof(char) * (strlen(tens) + strlen(ones) + 2));
        sprintf(final, "%s-%s", tens, ones);
        free(tens);
        free(ones);
        return final;
    } else {
        return tens;
    }
}

char *subThousandParse(int n) {
    assert(n < 1000);

    if (n == 0) {
        return singleDigit(0);
    }

    char *hundreds = NULL;

    char *remainder = NULL;

    if (n / 100) {
        char *temp = singleDigit(n / 100);
        hundreds = malloc(sizeof(char) * (9 + strlen(temp)));
        sprintf(hundreds, "%s hundred", temp);
        free(temp);
    }

    if (n % 100) {
        remainder = subHundredParse(n % 100);
    }

    if (hundreds && remainder) {
        char *final = malloc(sizeof(char) * (strlen(hundreds) + strlen(remainder) + 6));
        sprintf(final, "%s and %s", hundreds, remainder);
        free(hundreds);
        free(remainder);
        return final;
    } else if (hundreds) {
        return hundreds;
    } else if (remainder) {
        return remainder;
    } else {
        return NULL;
    }
}

char *numberToText(int number) {
    assert(number >= 1 && number <= 1000);

    if (number == 1000) {
        char *temp = "one thousand";
        char *str = malloc(sizeof(char) * (strlen(temp) + 1));
        strcpy(str, temp);
        return str;
    } else {
        return subThousandParse(number);
    }
}

int count(char *str) {
    int sum = 0;
    while (*str != '\0') {
        if (isalpha(*str)) {
            sum++;
        }
        str++;
    }
    return sum;
}

int main() {

    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        char *str = numberToText(i);
        int c = count(str);
        printf("-%s-%d\n", str, c);
        sum += c;
        free(str);
    }
    printf("Number of letters: %d\n", sum);

}