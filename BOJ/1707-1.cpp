#include<cstdio>
#include<queue>
#include<iostream>

using namespace std;

int Node;
int M[20001][20001];
int numbered[20001];
queue<int> Q;
int flag;

void search(){
	int now = Q.front();
	Q.pop();

	for(int i=0; i<Node; i++){
		if(M[now][i] == 1){
			if(numbered[i] == 0){
				if(numbered[now]==1)
					numbered[i] = 2;
				else
					numbered[i] = 1;
			}
			else{
				if(numbered[now] == numbered[i])
					flag = 1;
			}
			M[now][i] = 0;
			M[i][now] = 0;
			Q.push(i);
		}
	}
/*
	cout<<"----------------"<<endl;
	for(int i=0; i<Node; i++){
		for(int j=0; j<Node; j++)
			cout<<M[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;	
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
			fill_n(M[i],Node,0);
		fill_n(numbered,Node,0);
		flag = 0;

		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			M[x-1][y-1] = 1;
			M[y-1][x-1] = 1;
		}
		
		Q.push(0);
		numbered[0] = 1;
		search();
				
		if(flag)
			printf("NO\n");
		else	
			printf("YES\n");
	
	}
}
