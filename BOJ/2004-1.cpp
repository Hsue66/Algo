#include<cstdio>
#include<iostream>

using namespace std;

int main(){
  int N, M;
  scanf("%d%d",&N,&M);

  long long cnt2= 0;
  long long cnt5= 0;

  for(long long i=2; i<=N; i=i*2)
    cnt2 += N/i;
  for(long long i=5; i<=N; i=i*5)
    cnt5 += N/i;

  for(long long i=2; i<=(N-M); i=i*2)
    cnt2 -= (N-M)/i;
  for(long long i=5; i<=(N-M); i=i*5)
    cnt5 -= (N-M)/i;

  for(long long i=2; i<=M; i=i*2)
    cnt2 -= M/i;
  for(long long i=5; i<=M; i=i*5)
    cnt5 -= M/i;

  printf("%lld\n",min(cnt2,cnt5));
}
