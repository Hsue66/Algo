#include<cstdio>
//#include<iostream>
#define BOUND 100001

using namespace std;

int N,Cnt;
int G[BOUND],cnt[BOUND],check[BOUND];

void dfs(int now, int start, int num){
	num++;
	if(check[now] == 1)
		Cnt += (num - cnt[now]);
	else if(check[now] == -1)
		Cnt += 0;
	else{
		check[now] = 1;
		cnt[now] = num;

		if(start == now)
			Cnt += cnt[now];
		else
			dfs(G[now],start,num);
	}
	check[now] = -1;
}

int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		scanf("%d",&N);
		Cnt = 0;
		for(int i=0; i<N; i++){
			scanf("%d",&G[i]);
			G[i] = G[i] -1;
			check[i] = 0;
			cnt[i] = 0;
		}
		
		for(int i=0; i<N; i++){
			if(check[i] == 0)
				dfs(G[i],i,0);
			check[i] = -1;
		}

		printf("%d\n",N-Cnt);	
	}
}

