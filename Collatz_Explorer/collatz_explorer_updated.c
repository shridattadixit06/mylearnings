#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

struct entry
{
    long long num;
    long long steps;
    struct entry *next;
};

struct entry *table[TABLE_SIZE] = {NULL};

long long hash(long long num)
{
    return num % TABLE_SIZE;
}

void insert(long long num, long long steps)
{
    long long index = hash(num);

    struct entry *temp = malloc(sizeof(struct entry));

    if(temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    temp->num = num;
    temp->steps = steps;
    temp->next = NULL;

    if(table[index] == NULL)
    {
        table[index] = temp;
    }
    else
    {
        struct entry *temp2 = table[index];

        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }

        temp2->next = temp;
    }
}


long long lookup(long long num)
{
    long long index = hash(num);

    struct entry *temp = table[index];

    while(temp != NULL)
    {
        if(temp->num == num)
        {
            return temp->steps;
        }

        temp = temp->next;
    }

    return -1;
}

long long collatz_explorer(long long num, long long *peak)
{
    if(num == 1)
    {
        return 0;
    }


    if(num > *peak)
    {
        *peak = num;
    }

    long long cached = lookup(num);

    if(cached != -1)
    {
        return cached;
    }

    long long next;

    if(num % 2 == 0)
    {
        next = num / 2;
    }
    else
    {
        next = 3 * num + 1;
    }
    long long remaining_steps;

    remaining_steps = 1 + collatz_explorer(next, peak);

    insert(num, remaining_steps);


    return remaining_steps;
}


void free_table()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        struct entry *temp = table[i];

        while(temp != NULL)
        {
            struct entry *next = temp->next;

            free(temp);

            temp = next;
        }

        table[i] = NULL;
    }
}

int main()
{
    long long num = 13;

    long long peak = num;

    long long steps = collatz_explorer(num, &peak);


    printf("Starting number : %lld\n", num);
    printf("Steps           : %lld\n", steps);
    printf("Peak            : %lld\n", peak);


    printf("\nCached values:\n");

    printf("13 -> %lld\n", lookup(13));
    printf("40 -> %lld\n", lookup(40));
    printf("20 -> %lld\n", lookup(20));
    printf("10 -> %lld\n", lookup(10));
    printf("5  -> %lld\n", lookup(5));
    printf("16 -> %lld\n", lookup(16));
    printf("8  -> %lld\n", lookup(8));
    printf("4  -> %lld\n", lookup(4));
    printf("2  -> %lld\n", lookup(2));


    free_table();

    return 0;
}