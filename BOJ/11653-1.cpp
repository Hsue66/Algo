#include<cstdio>
//#include<iostream>
using namespace std;


int main(){
  int N;
  scanf("%d",&N);

  int d=2;
  do{
    if(N%d == 0){
      N = N/d;
      printf("%d\n",d);
    }
    else
      d++;
  }while(N!= 1);
}
