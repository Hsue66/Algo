#include<cstdio>
#include<iostream>
#define MAX 1000002

using namespace std;

long long Memo[MAX];

int main(){
  int Target;
  scanf("%d",&Target);
  Memo[1] = 0;
  Memo[2] = 1;
  Memo[3] = 1;

  for(int num =4; num <= Target; num++){
      long long case1 =-1;
      long long case2 = -1;

      if( num%3 == 0)
        case1 = 1+Memo[num/3];
      if( num%2 == 0)
        case2 = 1+Memo[num/2];
      Memo[num] = 1+Memo[num-1];

      if(case1 != -1 && case2 != -1)
        Memo[num] = min(Memo[num], min(case1,case2));
      else if(case1 != -1)
        Memo[num] = min(Memo[num],case1);
      else if(case2 != -1)
        Memo[num] = min(Memo[num],case2);
  }
  printf("%lld\n",Memo[Target] );
}
