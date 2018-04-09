#include<cstdio>
#include<iostream>

using namespace std;

int N,M;
int Map[101][101];
int numofB;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};


void bfs(int x, int y, int d, int cnt){
	if(x == N-1 && y == M-1){
		cnt++;
		if(numofB > cnt)
			numofB = cnt;
	}
	else{
		//cout<<x<<", "<<y<<":"<<d<<endl;
		//int a;
		//cin>> a;
		int except = (d+2)%4;
		int flag = 0;
		for(int i = 0; i<4; i++){
			if(except != i && flag < 2){
				int tx = x + dir[i][0];
				int ty = y + dir[i][1];
				if(((0 <= tx && tx < N) && (0 <= ty && ty < M))&& Map[tx][ty]==1){
					flag++;
					bfs(tx,ty,i,cnt+1);
				}	
			}
		}
	}
}

int main()
{
	scanf("%d%d",&N,&M);

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++)
			scanf("%1d",&Map[i][j]);
	}
	numofB = N*M;
	bfs(0,0,0,0);

	printf("%d\n",numofB);
}
