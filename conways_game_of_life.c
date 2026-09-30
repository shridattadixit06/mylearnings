#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
int check_identicals(int a[ROWS][COLS], int b[ROWS][COLS])
{
    for(int i=0;i<ROWS;++i)
    {
        for(int j=0;j<COLS;++j)
        {
            if(a[i][j]!=b[i][j])
                return 0;
        }
    }
    return 1;
}
void randomize_grid(int array[ROWS][COLS])
{
    for(int i=0;i<ROWS;++i)
    {
        for(int j=0;j<COLS;++j)
        {
            array[i][j] = rand() % 2;
        }
    }
}
int main()
{
    srand(time(NULL));
    int current[ROWS][COLS] = {0};
    int next[ROWS][COLS];
    int original[ROWS][COLS];
    int population[20];
    randomize_grid(current);
    copy_grid(current, original);
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

        if(generation >= 1 && generation % 2 == 1)
        {
            if(check_identicals(original, current))
                printf("Found period 2!\n");
        }

        printf("\n");
    }
    printf("\nPopulation history:\n");
    for(int i = 0; i < 20; i++)
    {
        printf("Generation %d: %d\n", i, population[i]);
    }
    

    return 0;
}