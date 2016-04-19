#include <stdio.h>
#include <queue>
#include <math.h>

using namespace std;

int now=0;
int number =0;
int wish = 0;
//int total= 0;i
queue<int> Queue;
long long A[2] = {1983,0};

int makeNum(int i)
{
	A[i%2] = ((long long)(A[(i-1)%2]*214013+2531011)%(long long)(pow(2.0,32.0)));
	//printf("%d\n", (int)(A[(i-1)%2]%10000+1));
	return (int)(A[(i-1)%2]%10000+1);
}

void find()
{
	int total =0;
	int idx = 1;
	while(idx <= number)
	{
		int temp = makeNum(idx);

		Queue.push(temp);
		now = now + temp;

//		printf("%d %d %d\n",wish,now,temp);

		if(wish == now)
			total++;
		else if(wish < now)
		{
			while(wish < now)
			{
				now = now - Queue.front();
				Queue.pop();
				if(wish == now)
					total++;
			}
		}

		idx++;
	}
	printf("%d\n",total);
}

int main()
{
	int testcase;
	scanf("%d",&testcase);

	for(int i=0; i<testcase; i++)
	{
		scanf("%d",&wish);
		scanf("%d",&number);

		queue<int> Queue;

		find();
		
		/*now = 0;
		total = 0;
		int A[2] = {1983,0};
*/

	}
}

