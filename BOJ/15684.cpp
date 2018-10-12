#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>

using namespace std;

int MAP[31][10]={0};
int N,H,M;

int check(int oId){
  stack<int> S;
  S.push(-1);
  for(int i=0; i<H; i++){
    for(int j=0; j<2; j++){
      if(MAP[i][oId-j] == 1 && 0 <= oId-j && oId-j < N-1){
        if(S.top() == oId-j){
          S.pop();
          if(j == 0)
            oId++;
          else
            oId--;
          break;
        }else{
          S.push(oId-j);
          if(j == 0)
            oId++;
          else
            oId--;
          break;
        }
      }
    }
  }
  //cout<<"oid "<<oId<<endl;
  return oId;
}

void addLadder(int map[31][10], int cnt){
  int idx = 0;
  for(idx; idx<N; idx++){
    if(idx != check(idx))
      break;
  }
  if(N-1 == idx)
    cout<<"OK "<< cnt<<endl;
  else{
    for(int i=0; i<H; i++){
      for(int j=0; j<N-1; j++){
        if(map[i][j] == 0){

        }
      }
    }
  }
}

int main(){
  scanf("%d%d%d",&N,&M,&H);
  for(int i=0; i<M; i++){
    int x,y;
    scanf("%d%d",&x,&y);
    MAP[x-1][y-1] = 1;
    if(0 <= y-2)
      MAP[x-1][y-2] = 2;
    if(N-1 > y)
      MAP[x-1][y] = 2;
  }


  int New[31][10]={0};
  copy(&MAP[0][0], &MAP[0][0]+H*(N-1), &New[0][0]);

  for(int i=0; i<H; i++){
    for(int j=0; j<N-1; j++)
      cout<<MAP[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl;
  for(int i=0; i<H; i++){
    for(int j=0; j<N-1; j++)
      cout<<New[i][j]<<" ";
    cout<<endl;
  }
}
