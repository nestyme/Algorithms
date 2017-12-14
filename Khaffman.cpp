#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct NODE
{
	unsigned char data;
	int freq;
	char code[255];
	NODE* left;
	NODE* right;
};
int bin_to_dec(char* c)
{
	int rez = 0;
	for(int i = 0; i < 8; i++)
	{
		if(c[i] == '1')
		{
			rez+= pow(2,(8-1-i));
		}
	}
	return rez;
}
NODE *Heapify(NODE *pointers[], int vol)
{
	NODE *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	printf("%d ",vol);
	temp->freq = pointers[vol - 1]->freq + pointers[vol - 2]->freq;
	temp->code[0] = 0;
	temp->left = pointers[vol - 1];
	temp->right = pointers[vol - 2];

	if (vol == 2)
		return temp;
	else
	{
		for (int i = 0; i < vol; i++)
			if (temp->freq > pointers[i]->freq)
			{
				for (int j = vol - 1; j > i; j--)
					pointers[j] = pointers[j - 1];

				pointers[i] = temp;
				break;
			}
	}
	return Heapify(pointers, vol - 1);
}

void code(NODE *root)
{
	if (root->left > 0)
	{	//printf("%d",root->left);
		strcpy(root->left->code, root->code);
		strcat(root->left->code, "0");
		code(root->left);
	}
	if (root->right > 0)
	{
		strcpy(root->right->code, root->code);
		strcat(root->right->code, "1");
		code(root->right);
	}
}

int main()
{
	FILE *f1, *f2, *f3;
	f1 = fopen("source.txt","r");
	f2 = fopen("tmp.txt","w");
	f3 = fopen("result.txt","w");
	int size1 = 0;
	int vol = 0;
	int count = 0;
	char c;
		if (f1 == NULL)
	{
		printf("file is not opened");
		system("pause");
		return 0;
	}
	printf("openning sucseed...\n");
	while((c = fgetc(f1))!=EOF)
	{
		size1++;
	}
	NODE* alph = (NODE*)malloc(size1*sizeof(NODE));
	rewind(f1);

	while((c = fgetc(f1)) != EOF)
	{
		for(int i = 0; i < vol; i++)
		{
			if(c == alph[i].data)
			{
				alph[i].freq++;
				count++;
				printf("%d ",vol);
				break;
			}

		}

		if (count == 0)
		{
			alph[vol].data = c;
			alph[vol].freq = 1;
			vol++;
			printf("%d ",vol);
		}
		count = 0;
	}
	printf("...%d\n",vol);
	//printf("%d\n",count);
	alph = (NODE*)realloc(alph, sizeof(NODE)*vol);
	for(int i = 0; i < vol; i++)
	{
		for(int j = i; j < vol; j++)
		{
			if(alph[i].freq < alph[j].freq)
			{
				NODE tmp;
				tmp = alph[i];
				alph[i] = alph[j];
				alph[j] = tmp;
			}
		}
	}
	for(int i = 0; i < vol; i++)
	{
		printf("%d)%c____%d\n",i,alph[i].data,alph[i].freq);
		alph[i].right = 0;
		alph[i].left = 0;
	}
	NODE** pointers = (NODE**)malloc(sizeof(NODE*)*vol);
	for(int i = 0; i < vol; i++)
	{
		pointers[i] = &alph[i];
	}
	NODE *root = Heapify(pointers, vol);
	code(root);
	printf("\nHaffman symbols encoding:");
	for(int i = 0; i < vol; i++)
	{
		printf("\n%c___%s",alph[i].data,alph[i].code);
	}
	rewind(f1);
	int tmp_vol = 0;
	while ((c = fgetc(f1)) != EOF)
	{
		for (int i = 0; i < vol; i++)
			if (c== alph[i].data)
			{
				fprintf(f2,"%s",alph[i].code);
				tmp_vol+=strlen(alph[i].code);
			}
	}
	fclose(f1);
	fclose(f2);
	int res = tmp_vol%8;
	printf("___%d___ ",tmp_vol);
	fprintf(f3,"%d ",tmp_vol);
	int yy = tmp_vol-tmp_vol%8;
	printf("%d",yy);
	f2 = fopen("tmp.txt","r");
	//char s[tmp_vol/8][8];
	printf("\n");
	char r[8];
	char tmp[8];
	//for(int i = 0; i < (tmp_vol - tmp_vol%8); i++)
	//{
	//	fscanf(f2,"%s",s[i]);
	//}
        //fscanf(f2,"%s",r);
   // for(int i = 0; i < tmp_vol/8; i++)
	//{
	    //printf("%s\t", s[i]);
	//}
	//for(int i = 0; i < (tmp_vol - tmp_vol%8); i++)
	//{   int e= bin_to_dec(s[i]);

		//char symbol =' '- e;
		//fprintf(f3,"%c",symbol);
	//}
	//for(int i = 7 ; i >= res ; i--)
	//{
		//r[i] = '0';
	//}
//	while((c = getchar(f2)) != EOF)
   // {
        for(int i = 0; i < yy/8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                r[j] = fgetc(f2);
                printf("%d, %d => %d\n", i, j, (int)r[j]);
            }
            fprintf(f3,"%c",bin_to_dec(r)-'0');
        }
   // }
   int length = tmp_vol%8;
   char w[length];
   fscanf(f2,"%s",w);
   fprintf(f3,"%c",bin_to_dec(w) - '0');
   //fprintf(f3,"%c",'bin_to_dec(w[]');
  //  res = tmp_vol
	//char symbol = bin_to_dec(r);
	//fprintf(f3,"%c",symbol);
	fclose(f2);
	fclose(f3);
	system("pause");
}
