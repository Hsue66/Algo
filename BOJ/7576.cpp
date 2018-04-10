#include<cstdio>
#include<queue>
//#include<iostream>

using namespace std;

int MAP[1001][1001];
int N,M;
queue<pair<int,int> > Q;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void bfs(){
	while(!Q.empty()){
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for(int i=0; i<4; i++){
			int tx = x + dir[i][0];
			int ty = y + dir[i][1];
			if((0 <= tx && tx < N) && (0 <= ty && ty < M) && MAP[tx][ty] == 0){
				Q.push(make_pair(tx,ty));
				MAP[tx][ty] = MAP[x][y] + 1;
			}
		}
	}
}

int main(){
	scanf("%d%d",&M,&N);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d",&MAP[i][j]);
			if(MAP[i][j] == 1)
				Q.push(make_pair(i,j));
		}
	}
	
	bfs();

	int max = 0;
	int flag = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(MAP[i][j] == 0)
				flag = 1;
			if(MAP[i][j] > max)
				max = MAP[i][j];
		}
	}

	if(flag)
		printf("-1\n");
	else
		printf("%d\n",max-1);
}
