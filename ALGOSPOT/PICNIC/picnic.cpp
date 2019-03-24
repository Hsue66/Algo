#include<string.h>
#include<stdio.h>

int numOfstudent;
int sizeOfpairs;
int	numOfpairs;
int total;
int *pairs;
//int *check;

void findPairs(int check[])
{
	int TorF = 0;
	int smallIdx =0;

	for(int i=0; i<numOfstudent; i++)
	{
		if(check[i]==1)
			TorF++;
	}

	if(TorF == numOfstudent)
	{
		total++;
		printf("one more group %d\n",total);
	}	
	else
	{
		for(int i=0; i<numOfstudent; i++)
		{
			if(check[i]==0)
			{
				smallIdx = i;
				printf("smallIdx : %d\n",smallIdx);
				break;
			}
		}

		for(int i=0; i<numOfpairs; i++)
		{
			printf("------ %d : %d ------",smallIdx,i);
			printf("pairs: %d %d\n",pairs[i*2],pairs[i*2+1]);
			printf("before checks: %d %d\n",check[pairs[i*2]],check[pairs[i*2+1]]);

			if( (pairs[i*2]==smallIdx||pairs[i*2+1]==smallIdx) 
					&& check[pairs[i*2]] !=1 && check[pairs[i*2+1]] !=1)
			{
				check[pairs[i*2]] =1;
				check[pairs[i*2+1]] =1;
				printf("after checks: %d %d\n\n",check[pairs[i*2]],check[pairs[i*2+1]]);
				findPairs(check);
			}
		}

	}

}

int main()
{
	int testcase;
	scanf("%d",&testcase);
	for(int i=0; i<testcase; i++)
	{
		scanf("%d %d",&numOfstudent,&numOfpairs);
		sizeOfpairs = numOfpairs*2;
		pairs = new int[sizeOfpairs];
		
		for(int j=0; j<sizeOfpairs; j++)
		{
			int temp;
			scanf("%d",&temp);
			pairs[j]=temp;
		}

		total = 0;
		int *check = new int[numOfstudent];
		memset(check,0,numOfstudent);
		findPairs(check);

		printf("%d",total);
	}
}
