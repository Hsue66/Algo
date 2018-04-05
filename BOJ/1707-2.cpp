#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

int Node;
int numbered[20001];
vector<int> G[20001];
queue<int> Q;
int flag;

void search(){
	int now = Q.front();
	Q.pop();

	for(int i=0; i<G[now].size(); i++){
		int linked = G[now][i];
		if(numbered[linked] == 0){
			if(numbered[now]==1)
				numbered[linked] = 2;
			else
				numbered[linked] = 1;
			Q.push(linked);
		}
	}
	/*
	cout<<"----------------"<<endl;
	for(int i=0; i<Node; i++){
		for(int j=0; j<Node; j++)
			cout<<M[i][j]<<" ";
		cout<<endl;
	}
	for(int i=0; i<Node; i++)
		cout<<numbered[i]<<" ";
	cout<<endl<<endl;
	*/

	if(!Q.empty())
		search();
}

int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		int m;
		scanf("%d%d",&Node,&m);

		for(int i=0; i<Node; i++)
			G[i].clear();		
		fill_n(numbered,Node,0);
		flag = 0;

		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			G[x-1].push_back(y-1);
			G[y-1].push_back(x-1);
		}
	
		for(int i=0; i<Node; i++){	
			if(numbered[i] == 0){
				Q.push(i);
				numbered[i] = 1;
				search();
			}
		}
	
		for(int i=0; i<Node; i++){
			for(int j=0; j<G[i].size(); j++){
				if(numbered[i] == numbered[G[i][j]])
					flag = 1;
			}
		}		
		if(flag)
			printf("NO\n");
		else	
			printf("YES\n");
	
	}
}
