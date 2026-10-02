#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define STEPS 1000
#define WALKS 1000
int main(){
    srand(time(NULL));
    int position = 0,step=0,total=0;
    int walks[1000],distance=0;
    for(int j=0;j<WALKS;++j)
    {
        position=0;
        for(int i=0;i<STEPS;++i)
        {
            if(rand()%2==0)
                step = 1;
            else
                step = -1;
            position+=step;

        }
        walks[j]=position;
        total+=position;
        distance+=abs(position);
    }
    float average_dist = (float)distance/1000;
    float average_pos = (float)total/1000;
    printf("Average distance travelled: %f",average_dist);
    printf("Average final pos: %f",average_pos);
    return 0;
}