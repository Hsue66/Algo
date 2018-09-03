#include<cstdio>
#include<iostream>
#define LIMIT 1002

using namespace std;

int Max[LIMIT] = {0};
int A[LIMIT];

int main(){
  int len;
  scanf("%d",&len );
  A[0] = 0;
  for(int i=1; i<len+1; i++)
    scanf("%d",&A[i] );

  Max[0] = 0;
  for(int i=1; i<len+1; i++){
    for(int t=0; t<i; t++){
      if(A[t] < A[i])
        Max[i] = max(Max[t]+1, Max[i]);
    }
  }

  int result = 0;
  for(int i=0; i<len+1; i++)
    result = max(result,Max[i]);

  printf("%d\n",result );
}
