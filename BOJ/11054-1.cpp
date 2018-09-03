#include<cstdio>
#include<iostream>
#define LIMIT 1002
using namespace std;

int Inc[LIMIT];
int Dec[LIMIT];
int A[LIMIT];

int main(){
  int len;
  scanf("%d",&len);
  A[0] = Inc[0] = 0;
  A[len+1] = Dec[0] = 0;
  for(int i=1; i<len+1; i++)
    scanf("%d",&A[i]);

  for(int i=1; i<len+1; i++){
    for(int t=0; t<i; t++){
      if(A[t] < A[i])
        Inc[i] = max(Inc[i], Inc[t]+1);
      if(A[len+1-t] < A[len+1-i])
        Dec[len+1-i] = max(Dec[len+1-i], Dec[len+1-t]+1);
    }
  }

  int result =0;
  for(int i=0; i<len+1; i++)
    result = max(Inc[i] + Dec[i], result);

  printf("%d\n",result-1 );
}
