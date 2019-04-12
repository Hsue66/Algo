#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int N,M,H,Min;
int L[30][10];
vector<pair<int,int> > possible;

bool down(){
  for(int j=0; j<N; j++){
    int n = j;
    for(int i=0; i<H; i++){
      if(L[i][j] == 1)
        j++;
      else if(j>0 && L[i][j-1] == 1)
        j--;
    }
    if(n!=j)
      return false;
  }
  return true;
}

void findPossible(){
  for(int i=0; i<H; i++){
    for(int j=0; j<N-1; j++){
      if(L[i][j] == 0){
        int flag = 1;
        if(j < N-1 && L[i][j+1] != 0)
          flag = 0;
        if(j > 0 && L[i][j-1] != 0)
          flag = 0;
        if(flag)
          possible.push_back(make_pair(i,j));
      }
    }
  }
}

void add(int idx, int cnt){
  if(idx == possible.size()){
    if( Min > cnt && down())
      Min = min(Min,cnt);
  }else{
    int x = possible[idx].first;
    int y = possible[idx].second;
    int flag = 1;
    if(y < N-1 && L[x][y+1] != 0)
      flag = 0;
    if(y > 0 && L[x][y-1] != 0)
      flag = 0;

    add(idx+1,cnt);
    if(flag && cnt < 3){
      L[x][y] = 1;
      add(idx+1,cnt+1);
      L[x][y] = 0;
    }
  }
}

int main(){
  scanf("%d%d%d",&N,&M,&H );
  while(M--){
    int a, b;
    scanf("%d%d",&a,&b );
    L[a-1][b-1] = 1;
  }

  Min = 4;
  findPossible();
  add(0,0);

  if(Min == 4)
    Min = -1;
  printf("%d\n",Min );
}
