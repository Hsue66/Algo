#include<cstdio>
//#include<iostream>

using namespace std;

long long Save[2];

int main(){
  int len;
  scanf("%d",&len );
  Save[0] =0;
  Save[1] =1;

  for(int n=1; n<len; n++){
    long long T0 = Save[0] + Save[1];
    long long T1 = Save[0];
    Save[0] = T0;
    Save[1] = T1;
  }

  printf("%lld\n",Save[0]+Save[1]);
}
