#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int N,M,CCTVlen,Min;
int MAP[8][8],PATH[8][8],KIND[8];
int CaseInfo[5] = {4,2,4,4,1};
int Case[5][4][4] = { {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}},
                      {{1,0,1,0},{0,1,0,1},{0,0,0,0},{0,0,0,0}},
                      {{1,1,0,0},{0,1,1,0},{0,0,1,1},{1,0,0,1}},
                      {{1,1,1,0},{0,1,1,1},{1,0,1,1},{1,1,0,1}},
                      {{1,1,1,1},{0,1,0,0},{0,0,1,0},{0,0,0,1}} };
vector<pair<pair<int,int>,int > > CCTV;
int Dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int count(){
  int Cnt = 0;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      // cout<<PATH[i][j]<<" ";
      if(PATH[i][j] == 0)
        Cnt++;
    }
    // cout<<endl;
  }
  return Cnt;
}

void mark(int x,int y, int d){
  int tx = x+ Dir[d][0];
  int ty = y+ Dir[d][1];
  if(0<= tx && tx <N && 0<= ty && ty <M && PATH[tx][ty] != 6){
    PATH[tx][ty] = 1;
    mark(tx,ty,d);
  }
}

void findCase(int idx){
  if(idx == CCTVlen){
    for(int i=0; i<N; i++)
      copy(MAP[i],MAP[i]+M,PATH[i]);

    for(int i=0; i<CCTVlen; i++){
      int x = CCTV[i].first.first;
      int y = CCTV[i].first.second;
      for(int d=0; d<4; d++){
        if(Case[CCTV[i].second][KIND[i]][d] == 1)
          mark(x,y,d);
      }
    }
    Min = min(Min,count());
  }else{
    for(int c=0; c<CaseInfo[CCTV[idx].second]; c++){
      KIND[idx] = c;
      findCase(idx+1);
    }
  }
}

int main(){
  scanf("%d%d",&N,&M );
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%d",&MAP[i][j] );
      if( 1<= MAP[i][j] && MAP[i][j] <6 )
        CCTV.push_back(make_pair(make_pair(i,j),MAP[i][j]-1));
    }
  }

  Min = N*M;
  CCTVlen = CCTV.size();
  findCase(0);
  printf("%d\n",Min );
}
