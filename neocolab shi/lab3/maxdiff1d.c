#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n1;
    scanf("%d", &n1);
    int arr[n1];
    int *p = arr;
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", p + i);
    }
    int max = 0;
    int diff, dr;
    for (int i = 0; i < n1; i++)
    {
        for (int j = i + 1; j < n1; j++) // this loop is pretty imp; you did i=i to n-i+1.
        {
            // calculate the MAX absolute difference in a array of integers
            dr = (arr[i] - arr[j]);
            diff = abs(dr);
            if (diff > max)
            {
                max = diff;
            }
        }
    }
    printf("%d", max);
    return 0;
}