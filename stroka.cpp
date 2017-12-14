#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
	char *p;
	char mask = 1;
	char* num;
	int r;
	scanf("%d",&r);
	malloc(r*sizeof(char));
	int n;
	int j;
	scanf("%s", num);
	p =num;

	for(j = 0; j < r; j++)
		{
			for(n = 0; n < 7; n++)
			{

				printf("\n%d ", ( (*p) & (1 << n)) >> n );
			}	
	p++;
		}
}
