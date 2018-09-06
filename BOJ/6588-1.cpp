#include<cstdio>
#include<iostream>
#define LIMIT 1000002
using namespace std;

int P[LIMIT];
int main(){
  fill_n(P,LIMIT,1);
  int b = 1;
  int n;
  P[1] = 0;
  while(scanf("%d",&n)==1){
    if(n==0)
      break;

    for(int t=2; t*t <= n; t++){
      int i = max(t*t, b/t*t);
      if(P[t]){
        while(i<=n){
          P[i] = 0;
          i = i+t;
        }
      }
    }
    b = n;
    int flag = 1;
    for(int i=2; i<=n/2; i++){
      if(P[i]==1 && P[n-i]==1){
        flag = 0;
        printf("%d = %d + %d\n",n,i,n-i);
        break;
      }
    }
    if(flag)
      printf("Goldbach's conjecture is wrong.\n");
  }
}
