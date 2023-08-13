#include <stdio.h>
#include <stdlib.h>

int isPrime (int no);

int main()
{
    int n, sum=0, i;
    printf ("Enter the number of elements you want in your array: ");
    scanf ("%d", &n);

    int* arr = (int*)malloc(n* sizeof(int));

    for (i=0; i<n; i++)
    {
        printf ("Enter element number %d: ", i+1);
        scanf ("%d", &arr[i]);
    }

    for (i=0; i<n; i++)
    {
        if (isPrime(arr[i]))
        {
            sum += arr[i];
        }
    }

    printf ("The sum of all prime numbers in the array is: %d", sum);
    
    return 0;
}

int isPrime (int no)
{
    if (no<=1)
    {
        return 0;
    }
    
    for (int i=2; i*i<=no; i++)
    {
        if (no % i == 0)
        {
            return 0;
        }
    }

     return 1;
}