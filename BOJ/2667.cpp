#include<cstdio>
#include<algorithm>
#include<queue>
//#include<iostream>

using namespace std;

int Cnt[320];
int idx = 0;
int Map[26][26]={0};
int N;
int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
queue<pair<int,int> > Q;

void search(){
	int nX = Q.front().first;
	int nY = Q.front().second;
	Q.pop();

	for(int i=0; i<4; i++){
		int tx = nX + dir[i][0];
		int ty = nY + dir[i][1];

		if((0 <= tx && tx < N) && (0 <= ty && ty < N) && Map[tx][ty] == 1){
			Q.push(make_pair(tx,ty));
			Map[tx][ty] = 0;
			Cnt[idx]++;
		}
	}

	if(!Q.empty())
		search();
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			scanf("%1d",&Map[i][j]);
	}
/*
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			cout<<Map[i][j]<<" ";
		cout<<endl;
	}*/

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(Map[i][j] == 1){
				Q.push(make_pair(i,j));
				Map[i][j] = 0;
				Cnt[idx]++;
				search();
				idx++;
			}
		}
	}
	printf("%d\n",idx);
	sort(Cnt,Cnt+idx);
	for(int i=0; i<idx; i++)
		printf("%d\n",Cnt[i]);

}
