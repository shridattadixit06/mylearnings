#include <stdio.h>
int count_alive(int array[3][3], int row, int column)
{
    int count = 0;

    for(int k = row - 1; k <= row + 1; ++k)
    {
        for(int m = column - 1; m <= column + 1; ++m)
        {
            if(m!=column || k!=row)
            {
                if(k>=0 && k<3 && m>=0 && m<3)
                {
                    if(array[k][m]==1)
                        count++;
                }
            }
        }
    }
    return count;
}
int next_state(int array[3][3], int row, int column)
{
    int neighbors = count_alive(array, row, column);

    if(array[row][column] == 1)
    {
        // cell is currently alive
        if(neighbors==2 || neighbors==3)
            return 1;
        else
            return 0;
    }
    else
    {
        // cell is currently dead
        if(neighbors==3)
            return 1;
        else
            return 0;
    }
}
void generate_next(int current[3][3], int next[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            next[i][j] = next_state(current, i, j);
        }
    }
}
int main()
{
    int a[3][3] = {
        {0,0,0},
        {1,1,1},
        {0,0,0}
    };

    int b[3][3];

    generate_next(a, b);
    generate_next(b, a);
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            printf("%d ", b[i][j]);
        }

        printf("\n");
    }
    
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            printf("%d ", a[i][j]);
        }

        printf("\n");
    }

    return 0;
}