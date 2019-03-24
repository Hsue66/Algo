#include<cstdio>
#include<vector>
//#include<iostream>

using namespace std;

int numOfs;
vector<int> G[11];
int checked[11];
int cnt;

void makePair(){
	int flag = -1;
	for(int i=0; i<numOfs; i++){
		if(checked[i] != 1){
			flag = i;
			break;
		}
	}

	int from, to;
	if(flag == -1)
		cnt++;
	else{
		from = flag;
		checked[from] = 1;
		for(int i=0; i<G[from].size(); i++){
			int to = G[from][i];
			if(checked[to] != 1){
				checked[to] = 1;
				makePair();
				checked[to] = 0;
			}
		}
		checked[from] = 0;
	}

}

int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		int M;
		scanf("%d%d",&numOfs,&M);
		fill_n(checked,numOfs,0);
		cnt = 0;

		while(M--){
			int tx,ty;
			scanf("%d%d",&tx,&ty);
			G[tx].push_back(ty);
			G[ty].push_back(tx);
		}
		
		makePair();
		printf("%d\n",cnt);

		for(int i=0; i<numOfs; i++)
			G[i].clear();
	}
}
