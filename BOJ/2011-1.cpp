#include<cstdio>
//#include<iostream>
#define DIV 1000000
#define LIMIT 5002
using namespace std;

int M[LIMIT];
int main(){
  char n;
  int idx =2;
  int b;
  scanf("%1d",&b);
  if(b == 0){
    M[0] = 0;
    M[1] = 0;
  }else{
    M[0] = 1;
    M[1] = 1;
  }
  
  while(scanf("%c",&n)== 1){
      int now = n-'0';
      int tnum = b*10 + now;
      b = now;

      if(n == '\n')
        break;

      if(now != 0)
        M[idx] = M[idx-1];
      if( 10 <= tnum && tnum <= 26)
        M[idx] = (M[idx]+M[idx-2])%DIV;
      idx++;
  }


  printf("%d\n",M[idx-1]);
}
