#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int points[] = {1000, 10000, 100000, 1000000};
    srand(time(NULL));
    int inside=0;
    int trials = 100;

    for (int j = 0; j < 4; ++j)
    {
        double total_error = 0;

        for (int trial = 0; trial < trials; ++trial)
        {
            int inside = 0;
            for(int i=0;i<points[j];++i)
            {
                double x = (double)rand() / RAND_MAX;
                double y = (double)rand() / RAND_MAX;
                if((x*x)+(y*y)<=1)
                    inside++;
            }
            double pi = 4.0 * inside / points[j];
            double error = pi - 3.141592653589793;
            if(error<0)
                error=-error;
            total_error+=error;
        }

        double average_error = total_error / trials;

        printf("Points: %d\n", points[j]);
        printf("Average error: %lf\n\n", average_error);
    }
    return 0;
}