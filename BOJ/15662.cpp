#include<iostream>
#include<cstdio>
#include<deque>
#define LIMIT 1001

using namespace std;

int T;
deque<int> List[LIMIT];
int visited[LIMIT];

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
  if(id+1 < T && visited[id+1] == 0){
    if(List[id][2] != List[id+1][6])
      turnList(id+1, dir*-1);
  }
  shiftList(id,dir);
}

int main(){
  scanf("%d",&T);
  for(int i=0; i<T; i++){
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
    fill_n(visited,T,0);
    turnList(id-1,dir);
  }
  int cnt=0;
  for(int i=0; i<T; i++)
    cnt += List[i][0];
  printf("%d\n",cnt);
}
