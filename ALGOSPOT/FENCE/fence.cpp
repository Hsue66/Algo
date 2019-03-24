#include<stdio.h>

int Strip[20000]={0};
int MaxSize[20000]={0};
int length=0;

void calcSize()
{
	for(int sidx=0; sidx<length; sidx++)
	{
		int height = Strip[sidx];
		int width =1;
		for(int i=sidx+1; i<length; i++)
		{
			if(height<=Strip[i])
				width++;
			else
				break;
		}

		for(int i=sidx-1; i>=0; i--)
		{
			if(height<=Strip[i])
				width++;
			else
				break;
		}
		
		MaxSize[sidx] = height*width;
	}

	int max = 0;
	for(int i=0; i<length; i++)
	{
		if(max<MaxSize[i])
			max = MaxSize[i];
	}
	printf("%d\n",max);
}

int main()
{
	int loopCnt;
	scanf("%d",&loopCnt);

	for(int i=0; i<loopCnt; i++)
	{
		scanf("%d",&length);

		for(int j=0; j<length; j++)
			scanf("%d",&Strip[j]);
		
		calcSize();

		for(int j=0; j<length; j++)
		{
			MaxSize[j] =0;
			Strip[j]=0;
		}
	}
}
