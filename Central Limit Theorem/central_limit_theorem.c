#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROLLS 10
#define EXPERIMENTS 100000

int main()
{
    srand(time(NULL));
    double sum = 0;
    for(int j = 0; j < ROLLS; j++)
    {
        int roll = rand() % 6 + 1;
        sum += roll;
    }
    double average = sum / ROLLS;
    printf("Average: %lf",average);
    return 0;
}