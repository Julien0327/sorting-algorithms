#include <stdio.h>
#define N 5
 
int main()
{
	int a[N] = {3,5,4,2,1};
	int i, j, k, t;
	
	for (i = 1; i < N; i++)
	{
    	for (j = i; j > 0; j--) 
		{
    		if (a[j] < a[j - 1]) 
			{
		        t = a[j];
		        a[j] = a[j - 1];
		        a[j - 1] = t;
		    }
    	}
	}

	
	for(i = 0; i < N; i++)
	printf("%d,",a[i]);
	return 0; 
}
