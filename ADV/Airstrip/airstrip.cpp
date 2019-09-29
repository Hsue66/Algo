#include<iostream>
#include<cstdio>

using namespace std;

int N,X;
int MAP[20][20];

int check(int Temp[20]){
  int flag = 0;
  int m[20] = {0};
  int before = Temp[0];
  for(int i=1; i<N; i++){
    // cout<<i<<": "<<Temp[i]<<endl;
    if(before == Temp[i])
      continue;
    else if(before+1 == Temp[i]){
      for(int t=i-1; t>=i-X; t--){
        if(t < 0)
          flag = 1;
        else if(m[t] == 0 && Temp[t] == before)
          m[t] = 1;
        else
          flag = 1;
        if(flag)
          break;
      }
      if(flag == 0)
        before++;
    }
    else if(before == Temp[i]+1){
      before--;
      for(int t=i; t<i+X; t++){
        if(t >= N)
          flag = 1;
        else if(m[t] == 0 && Temp[t] == before)
          m[t] = 1;
        else
          flag = 1;
        if(flag)
          break;
      }
      if(flag == 0)
        i = i+X-1;
    }
    else
      flag = 1;

    if(flag)
      break;
  }
  return flag;
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=0; t<testcase; t++){
    scanf("%d%d",&N,&X );
    int result = N*2;
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++)
        scanf("%d",&MAP[i][j] );
    }

    for(int i=0; i<N; i++)
      result -= check(MAP[i]);

    int T[20];
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++)
        T[j] = MAP[j][i];
      result -= check(T);
    }
    printf("#%d %d\n",t+1,result);
  }
}
