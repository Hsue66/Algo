#include<cstdio>
#include<queue>
//#include<iostream>
#define BOUND 101
#define MIN 987654321

using namespace std;

int M[BOUND][BOUND];
int C[BOUND][BOUND];
int N;
queue<pair<int,int> > Q;
queue<pair<int,int> > sQ;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void seperateL(){
	while(!Q.empty()){
		int x = Q.front().first;
		int y = Q.front().second;
		sQ.push(make_pair(x,y));
		Q.pop();
		for(int i=0; i<4; i++){
			int tx = x+dir[i][0];
			int ty = y+dir[i][1];
			if(0<=tx && tx <N && 0<=ty && ty <N && M[tx][ty]==0){
				M[tx][ty] = M[x][y];
				Q.push(make_pair(tx,ty));
			}
		}
	}
}

void spread(){
	while(!sQ.empty()){
		int x = sQ.front().first;
		int y = sQ.front().second;
		sQ.pop();
		for(int i=0; i<4; i++){
			int tx = x+dir[i][0];
			int ty = y+dir[i][1];
			if(0<=tx && tx <N && 0<=ty && ty <N && M[tx][ty]==-1){
				M[tx][ty] = M[x][y];
				C[tx][ty] = C[x][y] +1;
				sQ.push(make_pair(tx,ty));
			}
		}
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d",&M[i][j]);
			M[i][j] = -1+M[i][j];
			C[i][j] = 0;
		}
	}
	
	int cnt = 1;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(M[i][j] == 0){
				M[i][j] = cnt;
				Q.push(make_pair(i,j));
				seperateL();
				cnt++;
			}
		}
	}

	spread();	

	int min = MIN;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			for(int t=0; t<4; t++){
				int tx = i+dir[t][0];
				int ty = j+dir[t][1];
				if(0<=tx && tx <N && 0<=ty && ty <N && M[tx][ty]!=M[i][j]){
					int val = C[i][j] + C[tx][ty];
					if(min > val)
						min = val;
				}
			}
		}
	}
	
	if(min == MIN)
		min = 0;
	printf("%d\n",min);
}

