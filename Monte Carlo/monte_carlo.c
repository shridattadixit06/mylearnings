#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define POINTS 1000
int main()
{
    srand(time(NULL));
    int inside=0;
    for(int i=0;i<POINTS;++i)
    {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if((x*x)+(y*y)<=1)
            inside++;
    }
    printf("Total points: %d\n",POINTS);
    printf("Inside: %d\n",inside);
    double pi = 4.0 * inside / POINTS;
    printf("Estimated pi: %lf\n", pi);
    return 0;
}