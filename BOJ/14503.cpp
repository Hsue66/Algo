#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int M[51][51]={0};
int n,m;
int Move[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
int Back[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};

int dir[4] = {3,0,1,2};
int search(int X, int Y){
	if(M[X][Y]==0){
		M[X][Y] = 2;
		return 1;
	}
	else
		return 0;
}

void running(int X, int Y, int d){
	int cnt =0;
	while(cnt != 4){
		int tx = X+ Move[d][0];
		int ty = Y+ Move[d][1];
		d = (d+3)%4;
		//cout<<tx<<" "<<ty<<" "<<d<<endl;
		if(search(tx,ty)){
			X = tx;
			Y = ty;
			break;
		}
		cnt++;
	}
	if(cnt != 4)
		running(X,Y,d);
	else{
		X = X+Back[d][0];
		Y = Y+Back[d][1];
		if(M[X][Y]!=1)
			running(X,Y,d);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	int nx,ny,d;
	scanf("%d%d%d",&nx,&ny,&d);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			scanf("%d",&M[i][j]);
	}

	search(nx,ny);
	running(nx,ny,d);

	int cnt=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(M[i][j]==2) cnt++;
			//cout<<M[i][j]<<" ";
		}
		//cout<<endl;
	}

	printf("%d\n",cnt);

}
