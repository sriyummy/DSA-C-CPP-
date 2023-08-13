#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int size, i, sum=0, j;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    arr = (int*)malloc(size*sizeof(int));

    for (i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", (arr + i));
    }

    printf("\nEntered array elements are:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d  ", *(arr + i));
    }

    for (i = 0; i < size; i++)
    {
        for (j=2; j<(*arr(i+1)/2); j++)
        {
        	if (*(arr+i)%j != 0)
        	{
        		sum += *(arr + i);
        	}
        }
    }
    printf("Sum of prime elements is: %d", sum);

    free(arr);

    return 0;
}

