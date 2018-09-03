#include<cstdio>
#include<iostream>

using namespace std;

int main(){
  int len;
  scanf("%d",&len );

  int A;
  scanf("%d",&A );
  int b0 = A;
  int b1 = A;
  while(--len){
    scanf("%d",&A );
    int n0 = max(b0, b1);
    int n1 = max(b1+A, A);
    b0 = n0;
    b1 = n1;
  }
  printf("%d\n",max(b0,b1));
}
