#include<cstdio>
#include<queue>
#include<iostream>

using namespace std;

int MAP[101][101];
int G_MAP[101][101];
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
int N;
int Min = 200;
queue<pair<int, int> > Q;

void dfs(int x, int y){
	for(int i=0; i<4; i++){
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if( 0 <= tx && tx < N && 0 <= ty && ty < N && G_MAP[tx][ty] == 0){
			G_MAP[tx][ty] = G_MAP[x][y];
			dfs(tx,ty);
		}
	}
}

void bfs(){
	while(!Q.empty()){
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
	//	cout<<x<<","<<y<<endl;
		for(int i=0; i<4; i++){
			int tx = x + dir[i][0];
			int ty = y + dir[i][1];
			if( 0 <= tx && tx < N && 0 <= ty && ty < N && MAP[tx][ty] == -1){
				Q.push(make_pair(tx,ty));
				MAP[tx][ty] = MAP[x][y] + 1;
				G_MAP[tx][ty] = G_MAP[x][y];
			}
		}
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int t;
			scanf("%d",&t);
			G_MAP[i][j] = MAP[i][j] = t-1;
			if(t)
				Q.push(make_pair(i,j));
		}
	}

	int cnt = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(G_MAP[i][j] == 0){
				G_MAP[i][j] = ++cnt;
				dfs(i,j);
			}
		}
	}


	bfs();

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			for(int k=0; k<2; k++){
				int tx = i + dir[k][0];
				int ty = j + dir[k][1];
				if( 0 <= tx && tx < N && 0 <= ty && ty < N && G_MAP[tx][ty] != G_MAP[i][j]){
					int temp = MAP[tx][ty] + MAP[i][j];
					//cout<<i<<","<<j<<" "<<tx<<","<<ty<<":"<<temp<<endl;
					if(Min > temp)
						Min = temp;
				}
			}
		}
	}
	printf("%d\n",Min);
}
