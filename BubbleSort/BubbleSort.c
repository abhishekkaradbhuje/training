#include<stdio.h>
int main()
{
	int a[] = {2,8,5,1,9,7,3,4,6};
	int i,j,temp;
	int length = sizeof(a)/sizeof(int);
	printf("\nArray before sorting\n");
	for(i=0;i<length;i++)
	{
		printf("%d\t",a[i]);
	}
	for(i=0;i<length;i++)
	{
		for(j=0;j<length-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}	
		}
	}
	printf("\narray after sortig\n");
	for(i=0;i<length;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
