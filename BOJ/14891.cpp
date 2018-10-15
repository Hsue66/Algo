#include<iostream>
#include<cstdio>
#include<deque>

using namespace std;

deque<int> List[4];
int visited[4];

void shiftList(int id, int dir){
  if(dir == 1){
    int temp = List[id][7];
    List[id].erase(List[id].begin()+7);
    List[id].push_front(temp);
  }else{
    int temp = List[id][0];
    List[id].erase(List[id].begin());
    List[id].push_back(temp);
  }
}

void turnList(int id, int dir){
  visited[id] =1;
  if(0 <= id-1 && visited[id-1] == 0){
    if(List[id-1][2] != List[id][6])
      turnList(id-1, dir*-1);
  }
  if(id+1 < 4 && visited[id+1] == 0){
    if(List[id][2] != List[id+1][6])
      turnList(id+1, dir*-1);
  }
  shiftList(id,dir);
}

int main(){
  for(int i=0; i<4; i++){
    for(int j=0; j<8; j++){
      int t;
      scanf("%1d",&t);
      List[i].push_back(t);
    }
  }

  int K;
  scanf("%d",&K);
  for(int i=0; i<K; i++){
    int id,dir;
    scanf("%d%d",&id,&dir);
    fill_n(visited,4,0);
    turnList(id-1,dir);
  }
  printf("%d\n",List[0][0]*1+List[1][0]*2+List[2][0]*4+List[3][0]*8);
}
