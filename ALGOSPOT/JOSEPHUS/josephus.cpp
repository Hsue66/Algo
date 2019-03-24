//#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

queue<int> Q;
int N,K;

void find(){
  while(Q.size() != 2){
    Q.pop();
    for(int i=1; i<K; i++){
      Q.push(Q.front());
      Q.pop();
    }
  }
  int a = Q.front();
  Q.pop();
  int b = Q.front();
  Q.pop();
  if(a > b)
    printf("%d %d\n",b,a);
  else
    printf("%d %d\n",a,b);
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  while(testcase--){
    scanf("%d%d",&N,&K);
    for(int i=1; i<=N; i++)
      Q.push(i);
    find();
    while(!Q.empty())
      Q.pop();
  }
}
