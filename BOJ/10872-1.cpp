#include<cstdio>

int main(){
  int N;
  scanf("%d",&N );
  int fac=1;

  while(N)
    fac *= N--;

  printf("%d\n",fac);
}
