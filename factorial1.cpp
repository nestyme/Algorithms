#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void factorial(int num)
	{ 	int i,k,f,l_n=1;
		for(i=1;i<=num;i++)
			{	k=i;
				f=k%10;
				while (f==0)
					{	
						k/=10;
						f=k%10;
					}
				l_n*=f;
			while (l_n%10==0)
				{
					l_n/=10;
				}	
			}
		printf("\n%d",l_n%10);
	}
int main()
	{
		int a;
		scanf("%d",&a);
		factorial(a);
		system("pause");
		return 0;	
	}
