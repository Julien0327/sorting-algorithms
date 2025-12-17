#include <stdio.h>
#define N 5
 
int main()
{
	int a[N] = {3,5,4,2,1};
	int i, j, k, t;
	
	for (i = 0; i < N; i++)
	{
		t = a[i];
    	for (j = i - 1; j >= 0 && a[j] > t; j--) 
		{
    		a[j+1] = a[j];
    	}
    	a[j + 1] = t;
	}

	
	for(i = 0; i < N; i++)
	printf("%d,",a[i]);
	return 0; 
}

//	for (i = 0; i < N; i++)
//	{
//		t = a[i];
//    	for (j = i - 1; j >= 0; j--) 
//		{
//			if(a[j] > t)
//    			a[j+1] = a[j];
//			else break;
//    	}
//    	a[j + 1] = t;
//	}
