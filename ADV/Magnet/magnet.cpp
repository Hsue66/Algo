#include<iostream>
#include<cstdio>
#include<deque>
#include<vector>

using namespace std;

vector<deque<int> > Magnet(4);
int dir[4];

void check(int idx){
  if(0 < idx && dir[idx-1] == 0){
    if(Magnet[idx][6] != Magnet[idx-1][2]){
      dir[idx-1] = dir[idx]*-1;
      check(idx-1);
    }
  }
  if(idx < 3 && dir[idx+1] == 0){
    if(Magnet[idx][2] != Magnet[idx+1][6]){
      dir[idx+1] = dir[idx]*-1;
      check(idx+1);
    }
  }
}

void rotate(){
  for(int i=0; i<4; i++){
    if(dir[i] == 1){
      Magnet[i].push_front(Magnet[i].back());
      Magnet[i].pop_back();
    }
    else if(dir[i] == -1){
      Magnet[i].push_back(Magnet[i].front());
      Magnet[i].pop_front();
    }
  }
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=0; t<testcase; t++){
    int K;
    scanf("%d",&K );
    for(int i=0; i<4; i++){
      deque<int> t(8);
      for(int j=0; j<8; j++)
        scanf("%d",&t[j]);
      Magnet[i] = t;
    }

    while(K--){
      int idx,d;
      fill_n(dir,4,0);
      scanf("%d%d",&idx,&d );
      dir[idx-1] = d;
      check(idx-1);
      rotate();
    }
    int result = Magnet[0][0]+Magnet[1][0]*2+Magnet[2][0]*4+Magnet[3][0]*8;
    printf("#%d %d\n",t+1,result);
  }
}
