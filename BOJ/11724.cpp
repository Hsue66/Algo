#include<cstdio>
#include<queue>
//#include<iostream>

using namespace std;

int Node;
int cnt = 0;
int M[1001][1001] ={0};
queue<int> Q;
int checked[1001] = {0};

void BFS(){
	int now = Q.front();
	Q.pop();
	
	for(int i=0; i<Node; i++){
		if(M[now][i] && checked[i] == 0){
			Q.push(i);
			checked[i] = 1;
		}
	}

	if(!Q.empty())
		BFS();
	else
		cnt++;
}

void search(){
	BFS();
	for(int i=0; i<Node; i++){
		if(checked[i] == 0){
			Q.push(i);
			checked[i] = 1;
			break;
		}
	}
	if(!Q.empty())
		search();
}

int main(){
	int m;
	scanf("%d%d",&Node,&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		M[x-1][y-1] = 1;
		M[y-1][x-1] = 1;
	}

	checked[0] = 1;
	Q.push(0);
	search();
	printf("%d\n",cnt);
}
