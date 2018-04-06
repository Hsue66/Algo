#include<cstdio>
//#include<iostream>

using namespace std;

int Snum;
int G[100001];
int startFrom[100001] = {0};
int	times[100001] = {0};
int start;

int search(int now, int cnt){
	//cout<<now<<" ";
	if(times[now] != 0){
		if(startFrom[now] != start)
			return 0;
		else
			return cnt - times[now];
	}

	startFrom[now] = start;
	times[now] = cnt++;
	
	return search(G[now],cnt);
}

int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		scanf("%d",&Snum);
		for(int i=0; i<Snum; i++){
			int temp;
			scanf("%d",&temp);
			G[i] = temp-1;
			startFrom[i] = 0;
			times[i] = 0;
		}

		int sum = 0;
		for(int i=0; i<Snum; i++){
			if(times[i] == 0){
				start = i;
				sum += search(i,1);
			}
		}
		printf("%d\n",Snum-sum);
	}
}
