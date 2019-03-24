#include<stdio.h>
#include<queue>

using namespace std;

int main()
{
	int testcase;
	scanf("%d",&testcase);
	for(int i=0; i<testcase; i++)
	{
		int idx=0;
		char team;
		queue<int> Queue;

		do
		{
			scanf("%c",&team);

			if(team=='M')
			{
				Queue.push(idx);
				printf("%d\n",idx);
			}

			idx++;
		}
		while(getc(stdin)==' ');

		while(!Queue.empty())
		{
			printf("%d",Queue.front());
			Queue.pop();
		}
	}
}
