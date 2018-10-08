//#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define MAX 100001

using namespace std;

vector<vector<int> > Input(MAX);
queue<int> Q;
int Idx[MAX] = {0};

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0; i<N-1; i++){
    int s,t;
    scanf("%d%d",&s,&t);
    Input[s-1].push_back(t-1);
    Input[t-1].push_back(s-1);
  }

  Q.push(0);
  Idx[0] = -1;

  while(!Q.empty()){
    int root = Q.front();
    Q.pop();
    for(int i=0; i<Input[root].size(); i++){
      int val = Input[root][i];
      if(Idx[val] == 0){
        Idx[val] = root+1;
        Q.push(val);
      }
    }
  }

  for(int i=1; i<N; i++){
    printf("%d\n",Idx[i]);
  }
}
