#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 10
#define COLS 10
int count_alive(int array[ROWS][COLS], int row, int column)
{
    int count = 0;

    for (int k = row - 1; k <= row + 1; ++k)
    {
        for (int m = column - 1; m <= column + 1; ++m)
        {
            if (m != column || k != row)
            {
                if (k >= 0 && k < ROWS && m >= 0 && m < COLS)
                {
                    if (array[k][m] == 1)
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

    if (array[row][column] == 1)
    {
        // cell is currently alive
        if (neighbors == 2 || neighbors == 3)
            return 1;
        else
            return 0;
    }
    else
    {
        // cell is currently dead
        if (neighbors == 3)
            return 1;
        else
            return 0;
    }
}
int count_population(int array[ROWS][COLS])
{
    int count = 0;
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            if (array[i][j] == 1)
                count++;
        }
    }
    return count;
}
void generate_next(int current[ROWS][COLS], int next[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            next[i][j] = next_state(current, i, j);
        }
    }
}
void copy_grid(int source[ROWS][COLS], int destination[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            destination[i][j] = source[i][j];
        }
    }
}

void randomize_grid(int array[ROWS][COLS], int density)
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            array[i][j] = rand() % 100 < density;
        }
    }
}
int main()
{
    FILE *file = fopen("conway's_GOF_results.csv", "w");

    if (file == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }
    fprintf(file, "density,generation,average\n");
    srand(time(NULL));
    int current[ROWS][COLS] = {0};
    int next[ROWS][COLS];
    int population[10][100][20];
    for(int density=10;density<=100;density+=10)
    {
        for (int run = 0; run < 100; run++)
        {
            randomize_grid(current, density);
            for (int generation = 0; generation < 20; generation++)
            {
                population[density/10-1][run][generation] = count_population(current);
                generate_next(current, next);
                copy_grid(next, current);
            }
        }
    }
    for(int density=10;density<=100;density+=10)
    {
        for (int generation = 0; generation < 20; generation++)
        {
            int total = 0;

            for (int run = 0; run < 100; run++)
            {
                total += population[density/10-1][run][generation];
            }
            fprintf(file,"%d,%d,%d\n",density,generation,total/100);
        }
    }
    fclose(file);
    return 0;
}