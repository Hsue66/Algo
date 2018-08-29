#include<cstdio>
//#include<iostream>

using namespace std;

int main(){
  char val=0;
  int len =0;
  while(val != 10 && scanf("%c",&val)==1)
    len++;

  printf("%d\n",--len );
}
