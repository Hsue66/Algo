#include<cstdio>
#include<queue>
//#include<iostream>

using namespace std;

int MAP[101][101];
int N,M;
queue<pair<int,int> > Q;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int flag = 0;

void bfs(){
	while(!(Q.empty() || flag == 1)){
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for(int i=0; i<4; i++){
			int tx = x + dir[i][0];
			int ty = y + dir[i][1];
			if((0 <= tx && tx < N) && (0 <= ty && ty < M) && MAP[tx][ty] == 1){
				Q.push(make_pair(tx,ty));
				MAP[tx][ty] = MAP[x][y] + 1;
			}
			if(tx == N-1 && ty == M-1){
				printf("%d\n",MAP[tx][ty]-1);
				flag = 1;
				break;
			}
		}
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++)
			scanf("%1d",&MAP[i][j]);
	}

	Q.push(make_pair(0,0));
	MAP[0][0] = 2;
	bfs();
/*
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout<<MAP[i][j]<<" ";		
		}
		cout<<endl;
	} */
}

