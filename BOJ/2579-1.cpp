#include<cstdio>
#include<iostream>
#define LIMIT 301

using namespace std;

int Len;
int A[LIMIT];
int Max = 0;

void Step(int nIdx, int cnt, int sum){
  if(nIdx < Len){
    sum += A[nIdx];
    if(nIdx == Len-1)
      Max = max(Max, sum);
    else{
      if(cnt < 2)
        Step(nIdx+1, cnt+1,sum);
      Step(nIdx+2, 1, sum);
    }
  }
}

int main(){
  scanf("%d",&Len );
  for(int i=0; i<Len; i++)
    scanf("%d",&A[i] );

  Step(0,1,0);
  Step(1,1,0);

  printf("%d\n",Max );
}
