#include<iostream>
#include<cstdio>

using namespace std;

int D,W,K, Min;
int MAP[13][20],FILM[13][20];
int Change[13];

bool scan(){
  int flag =0;
  for(int j=0; j<W && flag == j; j++){
    int cnt0,cnt1;
    cnt0 = cnt1 = 0;
    for(int i=0; i<D; i++){
      if(MAP[i][j] == 1){
        cnt1++;
        cnt0 = 0;
      }else{
        cnt0++;
        cnt1 = 0;
      }
      if(cnt0 == K || cnt1 == K){
        flag++;
        break;
      }
    }
  }
  if(flag == W)
    return true;
  else
    return false;
}

void insert(int idx, int cnt){
  if(cnt >= Min)
    return;
  if(idx == D){
    for(int i=0; i<D; i++){
      if(Change[i] == 2)
        copy(FILM[i],FILM[i]+W,MAP[i]);
      else if(Change[i] == 0)
        fill_n(MAP[i],W,0);
      else
        fill_n(MAP[i],W,1);
    }
    if(scan())
      Min = min(Min,cnt);
  }else{
    // no
    Change[idx] = 2;
    insert(idx+1,cnt);
    // a
    Change[idx] = 0;
    insert(idx+1,cnt+1);
    // b
    Change[idx] = 1;
    insert(idx+1,cnt+1);
  }
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=1; t<=testcase; t++){
    scanf("%d%d%d",&D,&W,&K );
    for(int i=0; i<D; i++){
      for(int j=0; j<W; j++)
        scanf("%d",&FILM[i][j] );
    }

    Min = W;
    insert(0,0);
    printf("#%d %d\n",t,Min);
  }
}
