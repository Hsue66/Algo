#include<cstdio>
#include<cstring>
//#include<iostream>
#define DIV 1000000000

using namespace std;

int Last[10];

int main(){
  int len;
  scanf("%d",&len);

  Last[0] = 0;
  for(int i=1; i<10; i++)
    Last[i] = 1;

  for(int num=1; num<len; num++){
    int Temp[10] = {0};
    for(int i=1; i<9; i++)
      Temp[i] = (Last[i-1] + Last[i+1])%DIV;
    Temp[0] = Last[1];
    Temp[9] = Last[8];
    memcpy(Last,Temp,sizeof(Temp));
  }

  int Sum=0;
  for(int i=0; i<10; i++)
    Sum = (Sum+Last[i])%DIV;
  printf("%d\n",Sum);
}
