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
struct info
{
    long long num, steps, peak;
};
long long collatz_explorer(long long num, long long steps, long long *large)
{
    if(num==1)
        return steps;
    if(*large<num)
        *large=num;
    if(num%2==0)
        return collatz_explorer(num/2, steps+1, large);
    if((num)%2!=0)
        return collatz_explorer(3*num+1,steps+1, large);
}
long long collatz_explorer_all(long long num, long long steps, long long *large)
{
    printf("%lld,",num);
    if(num==1)
        return steps;
    if(*large<num)
        *large=num;
    if(num%2==0)
        return collatz_explorer_all(num/2, steps+1, large);
    else
        return collatz_explorer_all(3*num+1,steps+1, large);
}

int main()
{
    long long n = 10000, longest_seq=0,peak=0,peak_start,long_start,sum_seq_len=0,sum_peak=0; 
    struct info nums[n];   
    for(long long i=1;i<=n;++i)
    {
        long long steps=0,local_peak=i;
        steps = collatz_explorer(i, steps, &local_peak);
        sum_seq_len+=steps;
        sum_peak+=local_peak;
        if(longest_seq<steps)
        {
            longest_seq = steps;
            long_start=i;
        }
        if(peak<local_peak)
        {
            peak = local_peak;
            peak_start=i;
        }
        nums[i-1].num = i;
        nums[i-1].steps = steps;
        nums[i-1].peak = local_peak;

    }
    /*printf("\nNumber\tSteps\tPeak\n");
    for(long long i=0;i<n;++i)
    {
        printf("%lld\t%lld\t%lld\n",nums[i].num, nums[i].steps, nums[i].peak);
    }
  */
    printf(
        "longest_starting_number: %lld\nlongest_sequence: %lld\npeak: %lld\navg sequence length: %lld\navg peak: %lld\npeak_start: %lld\n"
        ,long_start,longest_seq, peak,sum_seq_len/n,sum_peak/n, peak_start);
    long long peak_steps=0,peak_peak=peak_start;
    collatz_explorer_all(peak_start,peak_steps,&peak_peak);
    return 0;
}