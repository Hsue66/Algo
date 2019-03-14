#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

int N,M,R,C,L;
int MAP[50][50];
int Ptype[7][4] = {{1,1,1,1},{1,0,1,0},{0,1,0,1},{1,0,0,1},{0,0,1,1},{0,1,1,0},{1,1,0,0}};
int Dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int Cnt;
queue<pair<pair<int,int>,int> > Nows;

void runaway(){
  while(!Nows.empty()){
    pair<int,int> Npos = Nows.front().first;
	int Nl = Nows.front().second;
    int Nx = Npos.first;
    int Ny = Npos.second;
    Nows.pop();
	if(MAP[Nx][Ny] != -1)
    	Cnt++;

    int Nv = MAP[Nx][Ny];
    MAP[Nx][Ny] = -1;

    for(int i=0; i<4; i++){
      if(Ptype[Nv-1][i]){
        //cout<<i<<endl;
        int Tx = Nx + Dir[i][0];
        int Ty = Ny + Dir[i][1];
        //cout<<MAP[Tx][Ty]<<endl;
        if(0<=Tx && Tx<N && 0<=Ty && Ty<M && MAP[Tx][Ty]!=0 && MAP[Tx][Ty]!=-1 && Ptype[MAP[Tx][Ty]-1][(i+2)%4]==1 && Nl > 0)
          Nows.push(make_pair(make_pair(Tx,Ty),Nl-1));
      }
    }
  }
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=1; t<=testcase; t++){
    scanf("%d%d%d%d%d",&N,&M,&R,&C,&L);
    Nows.push(make_pair(make_pair(R,C),L-1));
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++)
        scanf("%d",&MAP[i][j] );
    }
    Cnt = 0;
    runaway();
    printf("#%d %d\n",t,Cnt);
  }
}