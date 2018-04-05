#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

int Node;
int checked[1001];
vector<int> G[1001];
queue<int> Q;

void search(){
	int now = Q.front();
	Q.pop();

	for(int i=0; i<G[now].size(); i++){
		int linked = G[now][i];
		if(checked[linked] == 0){
			checked[linked]=1;
			Q.push(linked);
		}
	}

	if(!Q.empty())
		search();
}

int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		scanf("%d",&Node);

		for(int i=0; i<Node; i++)
			G[i].clear();		
		fill_n(checked,Node,0);
		int cnt = 0;

		for(int i=0; i<Node; i++){
			int x;
			scanf("%d",&x);
			G[i].push_back(x-1);
			G[x-1].push_back(i);
		}

		for(int i=0; i<Node; i++){	
			if(checked[i] == 0){
				Q.push(i);
				checked[i] = 1;
				cnt++;
				search();
			}
		}
		printf("%d\n",cnt);
	}
}
