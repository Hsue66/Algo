#include<cstdio>
//#include<iostream>
#define LIMIT 10001

int Num[LIMIT]={0};

int main(){
  int N;
  scanf("%d",&N );
  while(N--){
    int n;
    scanf("%d",&n);
    Num[n]++;
  }

  for(int i=0; i<LIMIT; i++){
    while(Num[i]--)
      printf("%d\n",i);
  }
}
