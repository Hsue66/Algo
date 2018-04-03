#include<cstdio>
#include<stack>
#include<queue>
//#include<iostream>

using namespace std;

int Node;
int M[1001][1001] ={0};
stack<int> S;
queue<int> Q;
int checked[1001] = {0};

void DFS(){
	int now = S.top();
	
	int i;
	for(i=0; i<Node; i++){	
		if(M[now][i] && checked[i] == 0){
			S.push(i);
			checked[i] = 1;
			printf("%d",i+1);
			break;
		}
	}
	if(i == Node)
		S.pop();
	else
	printf(" ");
	
	if(!S.empty())
		DFS();
	
}

void BFS(){
	int now = Q.front();
	printf("%d",now+1);
	Q.pop();
	
	for(int i=0; i<Node; i++){
		if(M[now][i] && checked[i] == 0){
			Q.push(i);
			checked[i] = 1;
		}
	}

	if(!Q.empty()){
		printf(" ");
		BFS();
	}
}

int main(){
	int m,first;
	scanf("%d%d%d",&Node,&m,&first);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		M[x-1][y-1] = 1;
		M[y-1][x-1] = 1;
	}

	checked[first-1] = 1;
	S.push(first-1);
	printf("%d ",first);
	DFS();
	printf("\n");

	
	fill_n(checked,Node,0);
	checked[first-1] = 1;
	
	Q.push(first-1);
	BFS();
	printf("\n");
}
