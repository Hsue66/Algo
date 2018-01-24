#include<cstdio>
#include<iostream>

using namespace std;

int Narr[11] = {0};

int add(int n)
{
	if(Narr[n] == 0 )
		return add(n-3)+add(n-2)+add(n-1);
	else
		return Narr[n];
}

int main()
{
	int loop;
	scanf("%d",&loop);
	Narr[0] = 1;
	Narr[1] = 1;
	Narr[2] = 2;
	for(;loop > 0;loop--){
		int num;
		scanf("%d",&num);
		printf("%d\n",add(num));
	}
}
