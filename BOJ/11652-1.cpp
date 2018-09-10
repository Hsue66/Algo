#include<cstdio>
//#include<iostream>
#include<queue>

using namespace std;

priority_queue<long long> Num;
int main(){
  int N;
  scanf("%d",&N );
  for(int i=0; i<N; i++){
    long long t;
    scanf("%lld",&t);
    Num.push(t);
  }

  long long before = Num.top();
  Num.pop();
  int cnt = 1;
  int Max = 1;
  long long result = before;
  while(!Num.empty()){
    long long now = Num.top();
    if(before == now)
      cnt++;
    else{
      if(Max <= cnt){
        Max = cnt;
        result = before;
      }
      cnt = 1;
    }
    before = now;
    Num.pop();
  }
  if(Max <= cnt){
    Max = cnt;
    result = before;
  }

  printf("%lld\n",result);
}
