#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{	int sum =0;
	int n;
	printf("Enter size of array:\n");
	scanf("%d",&n);
	malloc(n*sizeof(int));
	int a[n];
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
	//алгоритм Кадана
	malloc(sizeof(int));
	int ans = a[0];
	for (int r=0; r<n; ++r) 
	{
	sum += a[r];
	if (ans<sum)
		{	
			ans=sum;
		}
	if (sum<0)
		{	
			sum=0;
		}
	}
	printf("%d",ans);
	getch();
}
