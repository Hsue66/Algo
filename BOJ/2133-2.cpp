#include<cstdio>
//#include<iostream>
#define LIMIT 32

using namespace std;

int M[LIMIT];
int main(){
  int N;
  scanf("%d",&N );

  M[2] = 3;

  if(N%2 != 0)
    M[N] = 0;
  else{
    for(int i=4; i<=N; i=i+2){
      M[i] = 3*M[i-2];
      int t = i-2;
      while(t= t-2)
        M[i] += 2*M[t];
      M[i] += 2;
    }
  }

  printf("%d\n",M[N]);
}
