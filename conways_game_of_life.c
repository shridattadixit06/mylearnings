#include <stdio.h>
#define ROWS 10
#define COLS 10
int count_alive(int array[ROWS][COLS], int row, int column)
{
    int count = 0;

    for(int k = row - 1; k <= row + 1; ++k)
    {
        for(int m = column - 1; m <= column + 1; ++m)
        {
            if(m!=column || k!=row)
            {
                if(k>=0 && k<ROWS && m>=0 && m<COLS)
                {
                    if(array[k][m]==1)
                        count++;
                }
            }
        }
    }
    return count;
}
int next_state(int array[ROWS][COLS], int row, int column)
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
int count_population(int array[ROWS][COLS])
{
    int count=0;
    for(int i=0;i<ROWS;++i)
    {
        for(int j=0;j<COLS;++j)
        {
            if(array[i][j]==1)
                count++;
        }
    }
    return count;
}
void generate_next(int current[ROWS][COLS], int next[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            next[i][j] = next_state(current, i, j);
        }
    }
}
void copy_grid(int source[ROWS][COLS], int destination[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            destination[i][j] = source[i][j];
        }
    }
}
int main()
{
    int current[ROWS][COLS] = {0};
    int next[ROWS][COLS];
    int population[20];
    current[2][2] = 1;
    current[2][3] = 1;
    current[3][2] = 1;
    current[3][3] = 1;

    current[5][5] = 1;
    current[5][6] = 1;
    current[6][5] = 1;
    current[6][6] = 1;

    for(int generation = 0; generation < 20; generation++)
    {
        printf("Generation %d\n", generation);
        population[generation] = count_population(current);
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(current[i][j]==1)
                    printf("#");
                else
                    printf(".");
            }

            printf("\n");
        }
        generate_next(current, next);

        copy_grid(next, current);
    }
    printf("\nPopulation history:\n");
    for(int i = 0; i < 20; i++)
    {
        printf("Generation %d: %d\n", i, population[i]);
    }
    

    return 0;
}