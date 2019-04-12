#include<iostream>
#include<cstdio>

using namespace std;

int N,M,H,Min;
int L[30][10];

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

void add(int max, int cnt){
  if(max == cnt){
    if(Min > cnt && down())
      Min = min(Min,cnt);
  }else{
    for(int i=0; i<H; i++){
      for(int j=0; j<N-1; j++){
        if(L[i][j] == 0){
          int flag = 1;
          if(j < N-1 && L[i][j+1] != 0)
            flag = 0;
          if(j > 0 && L[i][j-1] != 0)
            flag = 0;
          if(flag){
            L[i][j] = 1;
            add(max,cnt+1);
            L[i][j] = 0;
          }
        }
      }
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
  for(int i=0; i<4; i++){
    if(Min == 4)
      add(i,0);
  }

  if(Min == 4)
    Min = -1;
  printf("%d\n",Min );
}
