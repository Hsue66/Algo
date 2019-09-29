#include<iostream>
#include<cstdio>

using namespace std;

int D,W,K;
int MAP[13][20];
int Min;

bool scan(int map[13][20]){
  int flag =0;
  for(int j=0; j<W && flag == j; j++){
    int cnt0,cnt1;
    cnt0 = cnt1 = 0;
    for(int i=0; i<D; i++){
      if(map[i][j] == 1){
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

void useD(int idx,int m[13][20], int cnt){
  for(int i=idx; i<D; i++){
    int t[20];
    copy(m[i],m[i]+W,t);

    // 0
    fill_n(m[i],W,0);
    if(scan(m))
      Min = min(Min, cnt+1);
    else
      useD(i+1,m,cnt+1);

    // 1
    fill_n(m[i],W,1);
    if(scan(m))
      Min = min(Min, cnt+1);
    else
      useD(i+1,m,cnt+1);

    // 복구
    copy(t,t+W,m[i]);
  }
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=1; t<=testcase; t++){
    scanf("%d%d%d",&D,&W,&K );
    for(int i=0; i<D; i++){
      for(int j=0; j<W; j++)
        scanf("%d",&MAP[i][j] );
    }

    Min = W;
    if(scan(MAP))
      Min = 0;
    else
      useD(0,MAP,0);
    printf("#%d %d\n",t,Min);
  }
}
