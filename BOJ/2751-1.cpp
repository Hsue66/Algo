#include<cstdio>
//#include<iostream>
#include<algorithm>
#define LIMIT 1000001
using namespace std;

int num[LIMIT];

int main(){
  int N;
  scanf("%d",&N );
  for(int i=0; i<N; i++)
    scanf("%d",&num[i]);

  sort(num, num+N);

  for(int i=0; i<N; i++)
    printf("%d\n",num[i]);
}
