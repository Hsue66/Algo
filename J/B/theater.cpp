#include<stdio.h>
#include<queue>

using namespace std;

int main()
{
	int total=0;
	int length;
	scanf("%d",&length);

	for(int i=0; i<length; i++)
	{
		char *string = new char[length];
		queue<int> Queue;
		scanf("%s",string);

		for(int j=0; j<length; j++)
		{
			Queue.push(string[j]);

			if(Queue.size()==2)				// check when queue is full
			{
				if(Queue.back()=='.')
					if(Queue.front()=='.')
						total++;			// available for couple
				Queue.pop();
			}
		}

		delete []string;
	}
	printf("%d\n",total);
}
