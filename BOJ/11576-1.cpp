#include<cstdio>
//#include<iostream>
#include<stack>

using namespace std;

stack<int> S;
int main(){
  int A,B,len;
  scanf("%d%d",&A, &B);
  scanf("%d",&len);
  int sum=0;
  while(len--){
    int n;
    scanf("%d",&n);
    sum = sum*A + n;
  }

  do{
    S.push(sum%B);
    sum = sum/B;
  }while(sum);

  while(!S.empty()){
    printf("%d ",S.top() );
    S.pop();
  }
  printf("\n");
}
