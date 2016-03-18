#include<stdio.h>
#include<string.h>

//int **MAP;
int height, width;
int pattern[4][4] = {{0,1,1,0},{1,0,1,-1},{1,0,1,1},{0,1,1,1}};

void setBlock(int (*MAP)[width],int x, int y, int p1x, int p1y, int p2x, int p2y)
{
	int** subMAP = new int*[height];
	for(int j=0; j<height; j++)
	{
		subMAP[j] = new int[width];
		memset(subMAP[j],0,width);
	}
	
	memcpy(subMAP,MAP,sizeof(int)*height*width);
	
	//mark
	if(x==-1 &&y ==-1 &&p1x ==-1&&p1y ==-1&&p2x ==-1&&p2y==-1)
	{}
	else
	{
		subMAP[x][y]= 1;
		subMAP[p1x][p1y]= 1;
		subMAP[p2x][p2y]= 1;
	}

	//full
	int TorF=0;
	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			if(subMAP[i][j]==0)
			{
				TorF=1;
				break;
			}
		}
	}

	if(TorF==0)
		total++;
	else
	{
		int startx,starty;
		//first empty space
		for(int i=0; i<height; i++)
		{
			for(int j=0; j<width; j++)
			{
				if(subMAP[i][j]==0)
				{
					startx= i;
					starty= j;
				}
			}
		}

		/*
		//set
		for(int i=0; i<4; i++)
		{
			if(subMAP[startx+pattern[0]][starty+pattern[1]] == 0
				&& subMAP[startx+pattern[2]][starty+pattern[3]] ==0)
			{
				setBlock(subMAP,startx,starty,startx+pattern[0],startx+pattern[1],
						startx+pattern[2],startx+pattern[3]);
			}
		}
*/
	
	}
}

/*
void showMAP()
{
	for(int l=0; l<height; l++)
		{
			for(int k=0; k<width; k++)
			{
				printf("%d ",MAP[l][k]);
			}
			printf("\n");
		}
}
*/

int main()
{
	int testcase;
	scanf("%d",&testcase);

	for(int i=0; i<testcase; i++)
	{
//		int height, width;
		scanf("%d %d%*c",&height,&width);

		int **MAP = new int*[height];
		for(int j=0; j<height; j++)
		{
			MAP[j] = new int[width];
			memset(MAP[j],0,width);
		}
		
		
		int space =0;
		for(int k=0; k<height; k++)
		{
			for(int l=0; l<width; l++)
			{
				char temp;
				if(l==width-1)
					scanf("%c%*c",&temp);
				else
					scanf("%c",&temp);
//				printf("%c %d %d",temp, height, width);
				
				if(temp=='#')
					MAP[k][l]=-1;
				else
					space++;
			}
		}

		
		// space possible or not
		if(space%3!=0)
		{
			printf("answer : 0\n");
		}
		else
		{
			setBlock(MAP,-1,-1,-1,-1,-1,-1);
		}

	}
}
