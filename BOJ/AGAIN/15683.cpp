#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N,M;
int MAP[8][8];
vector<pair<pair<int,int>, int> > CCTVlist;
int Clen = 0;
int Case[8];
int TYPE[5] = {4,2,4,4,1};
int CCTVs[5][4][4] = {  {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}},
                        {{1,0,1,0},{0,1,0,1},{0,0,0,0},{0,0,0,0}},
                        {{1,1,0,0},{0,1,1,0},{0,0,1,1},{1,0,0,1}},
                        {{1,1,1,0},{0,1,1,1},{1,0,1,1},{1,1,0,1}},
                        {{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}}  };
int Dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int MIN = 64;

void mark(){
  int PATH[8][8];
  for(int i=0; i<N; i++)
    copy(MAP[i],MAP[i]+M, PATH[i]);

  for(int i=0; i<Clen; i++){
    int Nx = CCTVlist[i].first.first;
    int Ny = CCTVlist[i].first.second;
    int Ctype = CCTVlist[i].second;
    for(int t=0; t<4; t++){
      if(CCTVs[Ctype][Case[i]][t] == 1){
        int tx = Nx;
        int ty = Ny;
        while(1){
          tx += Dir[t][0];
          ty += Dir[t][1];
          if(0 <= tx && tx < N && 0 <= ty && ty < M && MAP[tx][ty] != 6)
            PATH[tx][ty] = -1;
          else
            break;
        }
      }
    }
  }

  int cnt = 0;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(PATH[i][j] == 0)
        cnt++;
    }
  }

  MIN = min(MIN, cnt);
}

void findCase(int idx){
  if(idx == Clen){
    mark();
    // for(int i=0; i<Clen; i++)
    //   cout<<Case[i]<<" ";
    // cout<<endl;
  }else{
    for(int i=0; i<TYPE[CCTVlist[idx].second]; i++){
      Case[idx] = i;
      findCase(idx+1);
    }
  }
}

int main(){
  scanf("%d%d",&N,&M );
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%d",&MAP[i][j] );
      if(MAP[i][j] != 0 && MAP[i][j] != 6)
        CCTVlist.push_back(make_pair(make_pair(i,j),MAP[i][j]-1));
    }
  }

  Clen = CCTVlist.size();

  if(Clen > 0){
    //cout<<CCTVlist[0].second<<endl;
    for(int i=0; i<TYPE[CCTVlist[0].second]; i++){
      Case[0] = i;
      findCase(1);
    }
  }
  // Clen == 0인 경우
  else if(Clen == 0)
    mark();

  printf("%d\n",MIN );
}
