#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WALKS 1000

int main()
{
    srand(time(NULL));

    int steps[] = {100, 1000, 10000, 100000};
    int num_tests = 4;

    for(int k = 0; k < num_tests; ++k)
    {
        long long total_distance = 0;

        for(int j = 0; j < WALKS; ++j)
        {
            int position = 0;

            for(int i = 0; i < steps[k]; ++i)
            {
                if(rand() % 2 == 0)
                    position += 1;
                else
                    position -= 1;
            }

            total_distance += abs(position);
        }

        double average_distance = (double)total_distance / WALKS;

        printf("Steps: %d\n", steps[k]);
        printf("Average distance: %f\n", average_distance);
        printf("Random Walk ratio: %lf\n\n",average_distance/sqrt((double)steps[k]));
    }
    return 0;
}