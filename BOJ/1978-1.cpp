#include<cstdio>
//#include<iostream>

using namespace std;

int main(){
  int N;
  scanf("%d",&N);
  int cnt = N;
  while(N--){
    int n;
    scanf("%d",&n);

    if(n==1)
      cnt--;
    for(int i=2; i*i<=n; i++){
      if(n%i == 0){
        cnt--;
        break;
      }
    }
  }
  printf("%d\n",cnt );
}
