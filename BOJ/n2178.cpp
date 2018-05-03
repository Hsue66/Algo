#include<cstdio>
#include<queue>
//#include<iostream>
#define BOUND 101

using namespace std;

int N, M;
int MAP[BOUND][BOUND];
queue<pair<int,int> > Q;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void searchMaze(){
	while(!Q.empty()){
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for(int t=0; t<4; t++){
			int tx = x + dir[t][0];
			int ty = y + dir[t][1];
			if(0<=tx && tx<N && 0<=ty && ty<M && MAP[tx][ty]==1){
				MAP[tx][ty] = MAP[x][y] + 1;
				Q.push(make_pair(tx,ty));
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

	searchMaze();

	printf("%d\n",MAP[N-1][M-1]-1);
}
