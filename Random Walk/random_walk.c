#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));
    int position = 0,step=0;
    for(int i=0;i<1000;++i)
    {
        if(rand()%2==0)
            step = 1;
        else
            step = -1;
        position+=step;
    }
    printf("Final position: %d",position);
    return 0;
}