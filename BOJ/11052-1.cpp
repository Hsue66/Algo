#include<cstdio>
#include<iostream>
#define LIMIT 1002
using namespace std;

int Max[LIMIT];
int P[LIMIT];

int main(){
  Max[0] =0;
  int Target;
  scanf("%d",&Target );

  for(int i=0; i<Target; i++)
    scanf("%d",&P[i]);

  for(int num=1; num<=Target; num++){
    for(int i=0; i<num; i++)
      Max[num] = max(P[i]+Max[num-i-1], Max[num]);
  }

  printf("%d\n",Max[Target]);
}
