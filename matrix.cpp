#include <stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c,d,r;
    FILE* in,out;
    in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
    fprintf(in,"n m #1\n");
    fscanf(in,"%d %d",&a,&b);
    fprintf(in,"n m #2\n");
    fscanf(in,"%d %d",&c,&d);
    if (b!=c)
    	{
    		fprintf(out,"Error! Incorrect data!");
    		return 0;
    	}
 
    int matrix_one[a][b];
    int matrix_two[c][d];
 
    int i,j;    
 
// Запись в двумерные массивы 
 
    for(i = 0; i < a; i++)
    {	
	    for(j = 0; j < b; j++)
		{
            fscanf(in,"%i",&matrix_one[i][j]);
        }
 
    } 
    printf("\n\n\n");
 
    for(i = 0; i < c; i++)
	{
        for(j = 0; j < d; j++)
		{
            fscanf(in,"%i",&matrix_two[i][j]);
        }
 
    }
	 
    fprintf(out,"\n"); 
 	r=b+c;
		
   int matrix_mul[r];
    
        fprintf(in,"Rezult:\n");
 
 
        for(i = 0; i < a; i++)
		{
        
            for(j = 0; j < d; j++)
			{
                    
                int m;
                matrix_mul[i*a+j] = 0;
 
                for(m = 0; m < b; m++)
				{
 
                    matrix_mul[i*a+j] += (matrix_one[i][m]*matrix_two[m][j]);
            
                }
 
            }
 
        }
 
        for(i = 0; i < a; i++)
		{
        
            for(j = 0; j < d; j++)
			{
 
                fprintf(out,"%d ",matrix_mul[a*i+j]);
            
            }
 
            fprintf(out,"\n");
 
        }
    getch();
    return 0;
}
