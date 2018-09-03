#include<cstdio>
#include<iostream>
#define LIMIT 301

using namespace std;


int main(){
  int Len;
  scanf("%d",&Len );
  
  int b0,b1,b2;
  b0 = b2 = 0;
  scanf("%d",&b1);

  while(--Len){
	int A;
  	scanf("%d",&A);
	int n0 = max(b1,b2);
	int n1 = b0 + A;
	int n2 = b1 + A;

	b0 = n0;
	b1 = n1;
	b2 = n2;
  }
  printf("%d\n",max(b1,b2) );
}
