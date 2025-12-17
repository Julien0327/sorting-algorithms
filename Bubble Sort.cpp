#include <stdio.h>
#define N 5
 
int main()
{
	int a[N] = {9,2,4,5,1};
	int i, j, t;
	
	for(i = 1; i < N; i++)
	{
		for(j = 0; j < N-i; j++)
		{
			if(a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	for(i = 0; i < N; i++)
	printf("%d,",a[i]);
	return 0; 
}
