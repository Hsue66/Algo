#include<cstdio>
#include<iostream>

using namespace std;

int N;

int cntNum(int n){
  int cnt =0;
  int i=1;
  while(n*i <= N){
    int v = n*i++;
    while(v%n == 0){
      v = v/n;
      cnt++;
    }
  }
  return cnt;
}

int main(){
  scanf("%d",&N );
  int cnt2 = cntNum(2);
  int cnt5 = cntNum(5);

  printf("%d\n",min(cnt2, cnt5));
}
