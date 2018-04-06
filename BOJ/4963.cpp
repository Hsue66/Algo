#include<cstdio>
#include<algorithm>
#include<queue>
//#include<iostream>

using namespace std;

int idx = 0;
int Map[51][51]={0};
int w,h;
int dir[8][2] = {{-1,-1},{-1,1},{0,-1},{-1,0},{0,1},{1,-1},{1,0},{1,1}};
queue<pair<int,int> > Q;

void search(){
	int nX = Q.front().first;
	int nY = Q.front().second;
	Q.pop();

	for(int i=0; i<8; i++){
		int tx = nX + dir[i][0];
		int ty = nY + dir[i][1];

		if((0 <= tx && tx < h) && (0 <= ty && ty < w) && Map[tx][ty] == 1){
			Q.push(make_pair(tx,ty));
			Map[tx][ty] = 0;
		}
	}

	if(!Q.empty())
		search();
}

int main(){
	while(1){
		scanf("%d%d",&w,&h);
		idx = 0;
		if(w == 0 && h ==0)
			break;

		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++)
				scanf("%d",&Map[i][j]);
		}

/*
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++)
			cout<<Map[i][j]<<" ";
		cout<<endl;
	}	*/

		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(Map[i][j] == 1){
					Q.push(make_pair(i,j));
					//cout<<i<<"/"<<j<<" "<<idx<<endl;
					Map[i][j] = 0;
					search();
					idx++;
				}
			}
		}
		printf("%d\n",idx);
	}
}

