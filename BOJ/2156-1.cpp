#include<cstdio>
#include<iostream>

using namespace std;

int main(){
  int len;
  scanf("%d",&len );

  int b[3] = {0};
  while(len--){
    int now;
    scanf("%d",&now );
    int No = max(b[2],max(b[0],b[1]));
    int D1 = b[0] + now;
    int D2 = b[1] + now;
    b[0] = No;
    b[1] = D1;
    b[2] = D2;
  }
  printf("%d\n",max(b[2],max(b[0],b[1])));
}
