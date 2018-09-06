#include<cstdio>
//#include<iostream>

using namespace std;

long long P[101]={0};

int main(){
  int testcase, N;
  scanf("%d",&testcase );
  while(testcase--){
    scanf("%d",&N);
    P[0] = 1;
    P[1] = 1;
    P[2] = 1;
    P[3] = 2;
    P[4] = 2;
    for(int i=5; i<N; i++){
      if(P[i] == 0)
        P[i] = P[i-5] + P[i-1];
    }
    printf("%lld\n",P[N-1]);
  }
}
