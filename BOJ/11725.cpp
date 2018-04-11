#include<cstdio>
#include<queue>
#include<vector>
//#include<iostream>

using namespace std;

int N;
vector<int> G[100001];
int root[100001]={0};
queue<int> Q;

void bfs(){
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		for(int j=0; j<G[now].size(); j++){
			int nex = G[now][j];
			if(root[nex] == 0){
				root[nex] = now+1;
				Q.push(nex);
			}
		}
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N-1; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x-1].push_back(y-1);
		G[y-1].push_back(x-1);
	}

	Q.push(0);
	root[0] = -1;
	bfs();
	
	for(int i=1; i<N; i++)
		printf("%d\n",root[i]);
}
