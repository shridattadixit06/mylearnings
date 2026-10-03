#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define EXPERIMENTS 100000

int main()
{
    srand(time(NULL));
    double average[EXPERIMENTS][4];
    int rolls[4] = {10,100,1000,10000};
    double sum = 0,sum_10=0,sum_100=0,sum_1000=0,sum_10000=0;
    double average_of_10=0,average_of_100=0,average_of_1000=0,average_of_10000=0;
    for(int i=0;i<EXPERIMENTS;++i)
    {
        for(int j = 0; j < 4; j++)
        {
            sum=0;
            for(int k=0;k<rolls[j];++k)
            {
                int roll = rand() % 6 + 1;
                sum += roll;
            }
            average[i][j] = sum / rolls[j];
        }
    }
    for(int i=0;i<EXPERIMENTS;++i)
    {
        for(int j=0;j<4;++j)
        {
            if(j==0)
                sum_10+=average[i][j];
            else if(j==1)
                sum_100+=average[i][j];
            else if(j==2)
                sum_1000+=average[i][j];
            else
                sum_10000+=average[i][j];
        }
    }
    average_of_10=sum_10/EXPERIMENTS;
    average_of_100=sum_100/EXPERIMENTS;
    average_of_1000=sum_1000/EXPERIMENTS;
    average_of_10000=sum_10000/EXPERIMENTS;

    printf("Average of 10 rolls in 100000: %lf\n",average_of_10);
    printf("Average of 100 rolls in 100000: %lf\n",average_of_100);
    printf("Average of 1000 rolls in 100000: %lf\n",average_of_1000);
    printf("Average of 10000 rolls in 100000: %lf\n",average_of_10000);
    double var_sum_10=0, var_sum_100=0,var_sum_1000=0,var_sum_10000=0;
    for(int i=0;i<EXPERIMENTS;++i)
    {
        for(int j=0;j<4;++j)
        {
            if(j==0)
                var_sum_10+=average[i][j];
            else if(j==1)
                var_sum_100+=average[i][j];
            else if(j==2)
                var_sum_1000+=average[i][j];
            else
                var_sum_10000+=average[i][j];
        }
    }
    double var_10 = var_sum_10/EXPERIMENTS;
    double var_100 = var_sum_100/EXPERIMENTS;
    double var_1000 = var_sum_1000/EXPERIMENTS;
    double var_10000 = var_sum_10000/EXPERIMENTS;

    double sd_10 = sqrt(var_10);
    double sd_100 = sqrt(var_100);
    double sd_1000 = sqrt(var_1000);
    double sd_10000 = sqrt(var_10000);

    printf("standard deviation of 10-rolls column = %lf\n",sd_10); 
    printf("standard deviation of 100-rolls column = %lf\n",sd_100); 
    printf("standard deviation of 1000-rolls column = %lf\n",sd_1000); 
    printf("standard deviation of 10000-rolls column = %lf\n",sd_10000); 

    return 0;
}