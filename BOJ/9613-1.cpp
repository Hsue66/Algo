#include<cstdio>
//#include<iostream>
#define LIMIT 101

using namespace std;

int GCD(int a, int b){
  if(b == 0)
    return a;
  else
    GCD(b, a%b);
}

int A[LIMIT];
int main(){
  int testcase;
  scanf("%d",&testcase );
  while(testcase--){
    int n;
    scanf("%d",&n );
    for(int i=0; i<n; i++)
      scanf("%d",&A[i]);

    long long sum=0;
    for(int i=0; i<n-1; i++){
      for(int j=i+1; j<n; j++)
        sum += GCD(A[i],A[j]);
    }
    printf("%lld\n",sum);
  }
}
