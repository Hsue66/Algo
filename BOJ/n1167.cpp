#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
#define BOUND 100001

using namespace std;

vector<pair<int,int> > G[BOUND];
int V;
int MAX = 0;
int Idx = 0;
queue<pair<int,int> > Q;
int check[BOUND];

void bfs(){
	while(!Q.empty()){
		int node = Q.front().first;
		int val = Q.front().second;
		Q.pop();
		for(auto it=G[node].begin(); it!=G[node].end(); ++it){
			int next = (*it).first;
			if(check[next] == 0){
				check[next] = 1;
				int sum = (*it).second + val;
				Q.push(make_pair(next,sum));
				if(MAX < sum){
					MAX = sum;
					Idx = next;
				}
			}
		}
	}
}

int main(){
	scanf("%d",&V);
	for(int i=0; i<V; i++){
		int root, node, weight;
		scanf("%d",&root);
		while(1){
			scanf("%d",&node);
			if(node == -1)
				break;
			scanf("%d",&weight);
			G[root-1].push_back(make_pair(node-1,weight));
		}
	}

	for(int i=0; i<2; i++){
		fill_n(check,V,0);
		MAX = 0;
		Q.push(make_pair(Idx,MAX));
		check[Idx] = 1;
		bfs();
	}

	printf("%d\n",MAX);
}
