#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int points[] = {1000, 10000, 100000, 1000000};
    srand(time(NULL));
    int inside=0;
    for(int j=0;j<4;++j)
    {
        int inside=0;
        for(int i=0;i<points[j];++i)
        {
            double x = (double)rand() / RAND_MAX;
            double y = (double)rand() / RAND_MAX;
            if((x*x)+(y*y)<=1)
                inside++;
        }
        printf("Total points: %d\n",points[j]);
        printf("Inside: %d\n",inside);
        double pi = 4.0 * inside / points[j];
        printf("Estimated pi: %lf\n", pi);
    }
    return 0;
}