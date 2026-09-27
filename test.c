#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
struct entry
{
    long long num,steps;
    struct entry *next;
};
long long hash(long long num)
{
    return num%TABLE_SIZE;
}
struct entry *table[TABLE_SIZE];
void insert(long long num, long long steps)
{
    long long index = hash(num);
    struct entry *temp = (struct entry *)malloc(sizeof(struct entry));
    temp->num = num;
    temp->steps = steps;
    temp->next = NULL;
    if(table[index]==NULL)
    {
        table[index] = temp;
    }
    else
    {
        struct entry *temp2 = table[index];
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next = temp;
    }
}
long long lookup(long long num)
{
    long long index = hash(num);
    struct entry *temp = table[index];
    while(temp!=NULL)
    {
        if(temp->num==num)
            return temp->steps;
        else
            temp=temp->next;
    } 
    return -1;
}
int main()
{
    insert(5, 10);
    insert(15, 20);
    insert(25, 30);
    printf("%lld\n",lookup(5));
    printf("%lld\n",lookup(15));
    printf("%lld\n",lookup(25));
    printf("%lld\n",lookup(99));
    return 0;
}