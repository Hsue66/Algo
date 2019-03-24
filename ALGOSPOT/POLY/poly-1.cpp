#include<iostream>
#include<cstdio>
#define MAX 102
#define LIMIT 10000000

using namespace std;

int M[MAX];

int main(){
  int testcase;
  scanf("%d",&testcase );
  while(testcase--){
    int N;
    scanf("%d",&N );

    M[1] = 1;
    M[2] = 2;
    for(int i=3; i<=N; i++){
      long long temp = (M[1]+M[i-2])%LIMIT;
      for(int j=2; j<i; j++)
        temp = (temp + 2*M[j])%LIMIT;
      M[i] = temp%LIMIT;
    }

    printf("%d\n",M[N]);
  }
}
