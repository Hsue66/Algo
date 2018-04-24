#include<cstdio>
#include<queue>
#include<vector>
//#include<iostream>
#define MAX 20001

using namespace std;

int V;
vector<int> G[MAX];
queue<pair<int,int> > Q;
int check[MAX];
int flag;

void bfs(){
	while(!Q.empty()){
		int now = Q.front().first;
		int before = Q.front().second;
		Q.pop();
		for(auto i=0; i<G[now].size(); i++){
			int next = G[now][i];
			if(next != before){
				int temp = (check[now]+1)%2;
				if(check[next] == -1){
					check[next] = temp;
					Q.push(make_pair(next,now));
				}
				else{
					if(check[next] != temp)
						flag = 1;
				}
			}
		}
	}
}

int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		int E;
		scanf("%d%d",&V,&E);
		flag = 0;
		fill_n(check,V,-1);
		while(E--){
			int x,y;
			scanf("%d%d",&x,&y);
			G[x-1].push_back(y-1);
			G[y-1].push_back(x-1);
		}
	
		for(int i=0; i<V; i++){
			if(check[i] == -1){
				check[i] = 0;
				Q.push(make_pair(i,-1));
				bfs();
			}
		}
	
		if(flag)
		printf("NO\n");	
		else
		printf("YES\n");
	
		for(int i=0; i<V; i++)
			G[i].clear();
	}
}
