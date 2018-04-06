#include<cstdio>
#include<queue>
#include<vector>
#include<iostream>

using namespace std;

int Snum;
vector<int> G[100001];
queue<int> Q;
int passed[100001] = {0};
int	visited[100001] = {0};


void search(int start, int now){
	//cout<<now<<" ";
	int nex = G[now][0];
	if(start == now)
		visited[start] = 1;
	else if(visited[nex] == 0){
		passed[now]++;
		Q.push(now);
		if(passed[nex] < 2)
			search(start,nex);
	}
}

int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		scanf("%d",&Snum);
		for(int i=0; i<Snum; i++){
			int temp;
			scanf("%d",&temp);
			G[i].push_back(temp-1);
		}

		for(int i=0; i<Snum; i++){
			if(visited[i] == 0){
				//cout<<i<<" ";
				search(i,G[i][0]);
				while(!Q.empty()){
					if(visited[i] == 1)
						visited[Q.front()] = 1;
					Q.pop();
				}
				fill_n(passed,Snum,0);
				//cout<<endl;
			}
		}
	
		int num = 0;
		for(int i=0; i<Snum; i++){
			if(!visited[i])
				num++;
		}
		
		printf("%d\n",num);

		// graph clear
		for(int i=0; i<Snum; i++){
			G[i].clear();
			visited[i] = 0;
		}
	}
}
