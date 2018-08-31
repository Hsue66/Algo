#include<cstdio>
#include<iostream>
#define DIV 10007
using namespace std;

int Save[10];

int main(){
  int len;
  scanf("%d",&len );
  fill_n(Save,10,1);

  for(int n=1; n<len; n++){
    int sub = 0;
    for(int i=0; i<10; i++){
      int Temp = Save[i];
      Save[i] = (Save[i]+sub)%DIV;
      sub = (Temp+sub)%DIV;
    }
  }

  int Sum=0;
  for(int i=0; i<10; i++)
    Sum = (Sum+Save[i])%DIV;
  printf("%d\n",Sum );
}
