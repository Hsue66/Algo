#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
//#include<iostream>

using namespace std;

int N;
vector<pair<int,int> > G[100001];
queue<int> Q;
int fromR[100001];

void bfs(){
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		int sum = fromR[now];
		//for(int i=0; i<G[now].size(); i++){
		for(auto i=G[now].begin(); i != G[now].end(); ++i){
			int nex = (*i).first;
			if(fromR[nex] == -1){
				fromR[nex] = sum+(*i).second;
				Q.push(nex);
			}
		}
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		int root,node,weight;
		scanf("%d",&root);
		while(1){
			scanf("%d",&node);
			if(node == -1)
				break;
		
			scanf("%d",&weight);
			G[root-1].push_back(make_pair(node-1,weight));
		}
	}
	
	fill_n(fromR,N,-1);
	fromR[0]=0;
	Q.push(0);
	bfs();

	int max = 0;
	int root;
	for(int i=0; i<N; i++){
		if(max < fromR[i]){
			max = fromR[i];
			root = i;
		}
		fromR[i] = -1;
	}

	fromR[root] = 0;
	Q.push(root);
	bfs();
	
	sort(fromR,fromR+N);
	
	printf("%d\n",fromR[N-1]);
}

