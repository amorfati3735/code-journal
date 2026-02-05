// You are using GCC
#include <stdio.h>
#include <limits.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int *p = arr;
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", p + i);
    }
    int et;
    int max = 0;
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        et = *(p + i);
        // max and min checks are independent
        // array out of bounds is a common issue
        if (et <= min)
        {
            min = et;
        }
        if (et >= max)
        {
            max = et;
        }
    }
    printf("Highest temperatures: %d \n", max);
    printf("Lowest temperatures: %d", min);
}