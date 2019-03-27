#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int N,H,M;
int MAP[30][10] = {0};
vector<pair<int,int> > possible;
int Min = 4;
int LIMIT, Plen;

bool goDown(){
  bool flag = true;
  for(int i=0; i<N; i++){
    int line = i;
    for(int j=0; j<H; j++){
      if(MAP[j][line] == 1)
        line++;
      else if( 0 <line && MAP[j][line-1] == 1)
        line--;
    }
    if(line != i){
      flag = false;
      break;
    }
  }
  return flag;
}

void makePossible(){
  for(int j=0; j<N-1; j++){
    for(int i=0; i<H; i++){
      if(MAP[i][j] == 0 && MAP[i][j+1] == 0){
        if(0 < j){
          if(MAP[i][j-1] == 0)
            possible.push_back(make_pair(i,j));
        }
        else
          possible.push_back(make_pair(i,j));
      }
    }
  }
  Plen = possible.size();
}

void addNew(int idx, int cnt){
  if(cnt < 3 && idx < Plen){
    int tx = possible[idx].first;
    int ty = possible[idx].second;
    int flag = 0;
    if(MAP[tx][ty] == 1)
      flag = 1;
    else if( 0<ty && MAP[tx][ty-1] == 1)
      flag = 1;
    else if( MAP[tx][ty+1] == 1)
      flag = 1;
    if(flag == 0){
      // 추가
      MAP[tx][ty] = 1;
      addNew(idx+1,cnt+1);
      MAP[tx][ty] = 0;
    }
    //안추가
    addNew(idx+1,cnt);
  }
  else if(cnt == 3){
    if(goDown())
      Min = min(Min,cnt);
  }
  if(idx == Plen){
    if(goDown())
      Min = min(Min,cnt);
  }
}

int main(){
  scanf("%d%d%d",&N,&M,&H );
  for(int i=0; i<M; i++){
    int a,b;
    scanf("%d%d",&a,&b );
    MAP[a-1][b-1] = 1;
  }

  if(!goDown()){
    makePossible();
    if(Plen > 0){
      int tx = possible[0].first;
      int ty = possible[0].second;
      MAP[tx][ty] = 1;
      LIMIT = 1;
      addNew(1,1);
      MAP[tx][ty] = 0;
      addNew(1,0);
    }
  }
  else
    Min = 0;

  if(Min == 4)
    Min = -1;

  printf("%d\n",Min );
}
