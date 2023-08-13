#include <stdio.h>

int compare(int*, int*);
 
int main()
{
   int n1, n2, res;
  
   printf(" Input the first number : ");
   scanf("%d", &n1);
   printf(" Input the second  number : ");
   scanf("%d", &n2);   
   
   compare (&n1, &n2);
   
   return 0;
}

int compare(int*n1, int*n2) 
{
	if (*n1 > *n2)
	{
		printf ("%d is greater than %d", *n1, *n2);
	}
	else if (*n1 < *n2)
	{
		printf ("%d is lesser than %d", *n1, *n2);
	}
	else if (*n1 == *n2)
	{
		printf (" %d and %d are the same", *n1, *n2);
	} 
}

