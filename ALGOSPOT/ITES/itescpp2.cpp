#include <stdio.h>
#include <queue>
#include <math.h>

using namespace std;

// global var
int now=0;
int number =0;
int wish = 0;
queue<int> Queue;
long long A[2];

// number generator
int makeNum(int i)
{
	if(i==1)
		A[0] = 1983;
	A[i%2] = ((long long)(A[(i-1)%2]*214013+2531011)%(long long)(pow(2.0,32.0)));
	return (int)(A[(i-1)%2]%10000+1);
}


void find()
{
	int total =0;
	int idx = 1;

	// loop to find partition array
	while(idx <= number)
	{
		int temp = makeNum(idx);
		Queue.push(temp);

		now = now + temp;

		if(wish == now)
			total++;
		else if(wish < now)		// if bigger than wish -decrease value
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
	}
}

