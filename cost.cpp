#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	int loop;
	scanf("%d",&loop);
	
	for(int i=0;i<loop; i++)
	{
		queue<int> Queue;
		Queue.push(0);
		
		int days,cost=0;
		scanf("%d",&days);

		for(int j=0; j<days; j++)
		{
			int bus,case1,case2,case3;
		
			if(j>6)
				Queue.pop();

			scanf("%d",&bus);

			case1= cost+bus*1;
			case2= cost+3;
			case3= Queue.front()+16;
			
			cost=case1;
			if(cost>case2)
				cost = case2;
			if(cost>case3)
				cost = case3;

			Queue.push(cost);
//			printf("case: %d %d %d\n",case1,case2,case3);
//			printf("now: %d\n",cost);
		}
		printf("%d\n",cost);
		fflush(stdout);
	}
}
