#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define DELIM "\","

int count(char *str, char c, int len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}

int cmpstr(const void* a, const void* b)
{
    const char* aa = *(const char**)a;
    const char* bb = *(const char**)b;
    return strcmp(aa,bb);
}

int score(char *str) {
    int total = 0;
    for (int i = 0; i < strlen(str); i++) {
        total += str[i] - ('A' - 1);
    }
    return total;
}

int main()
{
    // Open the file
    FILE *fp = fopen("names.txt", "r");


    size_t pos = ftell(fp);    // Current position
    fseek(fp, 0, SEEK_END);    // Go to end
    size_t length = ftell(fp); // read the position which is the size
    fseek(fp, pos, SEEK_SET);  // restore original position

    // Create buffer for file
    char *buffer = malloc(sizeof(char) * (length + 1));
    buffer[length] = '\0';

    // read into buffer
    fread(buffer, sizeof(char), length, fp);

    // Count the words based on the separator
    int numWords = count(buffer, ',', length) + 1;

    // Create word array
    char **words = malloc(sizeof(char *) * numWords);

    // Loop through word count
    char *next = strtok(buffer, DELIM);
    for (int i = 0; i < numWords; i++) {
        // Clear all delimiters
        while (strlen(next) == 0) {
            next = strtok(NULL, DELIM);
        }
        // Allocate space
        words[i] = malloc(strlen(next) * sizeof(char));
        // Copy the word
        strcpy(words[i], next);
        // Advance
        next = strtok(NULL, DELIM);
    }


    // for (int i = 0; i < numWords; i++) {
    //     printf("%s\n", words[i]);
    // }

    qsort(words, numWords, sizeof(char *), cmpstr);

    // for (int i = 0; i < numWords; i++) {
    //     printf("%s\n", words[i]);
    // }

    uint64_t total = 0;

    for(int i = 0; i < numWords; i++) {
        int position = i + 1;
        int sc = score(words[i]);
        total += position * sc;

        //printf("%s score %d\n", words[i], total);
    }

    printf("%lld\n", total);


    fclose(fp);
}