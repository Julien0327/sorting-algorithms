#include <stdio.h>
#define N 5
 
int main()
{
	int a[N] = {3,5,4,2,1};
	int i, j, k, t;
	
	for(i = 0; i < N; i++)
	{
		k = i;//k=0
		for(j = i+1; j < N; j++)
		{//a[0] > a[3]
			if(a[k] > a[j])
			k = j;//k=3 k=4
		}
		
		t = a[i];//t=a[0]=3
		a[i] = a[k];//a[0]=a[3]=2
		a[k] = t;//a[3]=t=3
	}
	
	for(i = 0; i < N; i++)
	printf("%d,",a[i]);
	return 0; 
}
