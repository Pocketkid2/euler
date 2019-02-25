// ----------------------------------------
//	PROJECT EULER PROBLEM 32
//		https://projecteuler.net/problem=32
// ----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAXNUM 100000
#define SIZE 100

// Returns true if A, B, and C together are 1 - 9 pandigital
// A x B must = C
bool pandigital(int a, int b, int c);
bool pandigital2(int a, int b, int c);

// Returns true if the number N has been passed to the function before
bool seen(int n);

int main(int argc, char *argv[])
{
    int algo = 1;
    if (argc >= 2)
    {
        algo = atoi(argv[1]);
    }
    int sum = 0;

    if (algo == 1)
    {
        // start the stopwatch
        time_t start = time(NULL);

        for (int i = 1; i < MAXNUM; i++)
        {
            for (int j = 0; j < MAXNUM; j++)
            {
                if (pandigital(i, j, i * j))
                {
                    if (seen(i * j))
                    {
                        printf("Found new pandigital: %d x %d = %d\n", i, j, i * j);
                        sum += i * j;
                    }
                }
            }
        }

        time_t stop = time(NULL);

        printf("Time elapsed with algorithm 1: %f seconds\n", difftime(stop, start));
    }
    else if (algo == 2)
    {
        // start the stopwatch
        time_t start = time(NULL);

        for (int i = 1; i < MAXNUM; i++)
        {
            for (int j = 0; j < MAXNUM; j++)
            {
                if (pandigital2(i, j, i * j))
                {
                    if (seen(i * j))
                    {
                        printf("Found new pandigital: %d x %d = %d\n", i, j, i * j);
                        sum += i * j;
                    }
                }
            }
        }

        time_t stop = time(NULL);

        printf("Time elapsed with algorithm 2: %f seconds\n", difftime(stop, start));
    }

    printf("Total sum: %d\n", sum);
}

bool seen(int n)
{
    static int seen[SIZE];
    static int i = 0;
    for (int j = 0; j < i; j++)
    {
        if (seen[j] == n)
        {
            return true;
        }
    }
    seen[i] = n;
    i++;
    return false;
}

bool pandigital2(int a, int b, int c)
{
    char strA[10];
    char strB[10];
    char strC[10];
    char final[30] = {0};
    itoa(a, strA, 10);
    itoa(b, strB, 10);
    itoa(c, strC, 10);
    strcat(final, strA);
    strcat(final, strB);
    strcat(final, strC);
    bool count[10] = {0};
    int len = strlen(final);
    for (int i = 0; i < len; i++)
    {
        int x = final[i] - '0';
        if (x == 0)
        {
            return false;
        }
        if (count[x])
        {
            return false;
        }
        else
        {
            count[x] = true;
        }
    }
    for (int i = 1; i < 10; i++)
    {
        if (!count[i])
        {
            return false;
        }
    }
    return true;
}

bool pandigital(int a, int b, int c)
{
    uint8_t count[10] = {0};
    char strA[10];
    itoa(a, strA, 10);
    char strB[10];
    itoa(b, strB, 10);
    char strC[10];
    itoa(c, strC, 10);
    int lenA = strlen(strA);
    int lenB = strlen(strB);
    int lenC = strlen(strC);
    for (int i = 0; i < lenA; i++)
    {
        count[strA[i] - '0']++;
    }
    for (int i = 0; i < lenB; i++)
    {
        count[strB[i] - '0']++;
    }
    for (int i = 0; i < lenC; i++)
    {
        count[strC[i] - '0']++;
    }
    if (count[0])
    {
        return false;
    }
    for (int i = 1; i < 10; i++)
    {
        if (count[i] != 1)
        {
            return false;
        }
    }
    return true;
}