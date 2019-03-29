#include<iostream>
#include<cstdio>
#include<vector>
#include<deque>

using namespace std;

vector<deque<int> > Circles;
int rot[4];
int K;

void move(){
  for(int i=0; i<4; i++){
    if(rot[i] == -1){
      Circles[i].push_back(Circles[i].front());
      Circles[i].pop_front();
      rot[i] = 0;
    }
    else if(rot[i] == 1){
      Circles[i].push_front(Circles[i].back());
      Circles[i].pop_back();
      rot[i] = 0;
    }
  }
}

void rotate(int idx, int d){
  rot[idx] = d;
  if(idx-1 >= 0){
    if(Circles[idx][6] != Circles[idx-1][2] && rot[idx-1] == 0)
      rotate(idx-1, d*-1);
  }
  if(idx+1 < 4){
    if(Circles[idx][2] != Circles[idx+1][6] && rot[idx+1] == 0)
      rotate(idx+1, d*-1);
  }
}

int main(){
  for(int i=0; i<4; i++){
    deque<int> temp(8);
    for(int j=0; j<8; j++)
      scanf("%1d",&temp[j]);
    Circles.push_back(temp);
  }
  scanf("%d",&K );
  while(K--){
    int idx,dir;
    scanf("%d%d",&idx,&dir );
    rotate(idx-1,dir);
    move();
  }

  int sum = Circles[0][0]+2*Circles[1][0]+4*Circles[2][0]+8*Circles[3][0];
  printf("%d\n",sum );
}
