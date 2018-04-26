#include<cstdio>
#include<iostream>
#define MAX 1001
using namespace std;

int N,cnt;
int G[MAX],check[MAX];

void findCycle(int num){
	if(check[num] == 0){
		check[num] = 1;
		findCycle(G[num]);
	}
}

int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		scanf("%d",&N);
		fill_n(check,N+1,0);
		cnt = 0;
		for(int i=1; i<=N; i++)
			scanf("%d",&G[i]);

		for(int i=1; i<=N; i++){
			if(check[i]==0){
				findCycle(i);
				cnt++;
			}
		}

		printf("%d\n",cnt);
	}
}
