#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int N,L,Cnt;
int MAP[100][100];
int P[100];

void findRow(){
  for(int i=0; i<N; i++){
    int before = MAP[i][0];
    int flag = 0;
    fill_n(P,N,0);
    for(int j=1; j<N; j++){
      if(before == MAP[i][j])
        continue;
      else if(abs(before-MAP[i][j])>1)
        flag = 1;
      else if(before == MAP[i][j]+1){
        before--;
        for(int t=0; t<L; t++){
          if(j+t >= N)
            flag = 1;
          else if(P[j+t] == 1 || before != MAP[i][j+t])
            flag = 1;
          else
            P[j+t] = 1;
          if(flag)
            break;
        }
        j = j+L-1;
      }
      else if(before+1 == MAP[i][j]){
        for(int t=1; t<=L; t++){
          if(j-t < 0)
            flag = 1;
          else if(P[j-t] == 1 || before != MAP[i][j-t])
            flag = 1;
          else
            P[j-t] = 1;
          if(flag)
            break;
        }
        before++;
      }
      if(flag)
        break;
    }
    // cout<<flag<<endl;
    if(flag == 0)
      Cnt++;
  }
}

void findCol(){
  for(int j=0; j<N; j++){
    int before = MAP[0][j];
    int flag = 0;
    fill_n(P,N,0);
    for(int i=1; i<N; i++){
      if(before == MAP[i][j])
        continue;
      else if(abs(before-MAP[i][j])>1)
        flag = 1;
      else if(before == MAP[i][j]+1){
        before--;
        for(int t=0; t<L; t++){
          if(i+t >= N)
            flag = 1;
          else if(P[i+t] == 1 || before != MAP[i+t][j])
            flag = 1;
          else
            P[i+t] = 1;
          if(flag)
            break;
        }
        i = i+L-1;
      }
      else if(before+1 == MAP[i][j]){
        for(int t=1; t<=L; t++){
          if(i-t < 0)
            flag = 1;
          else if(P[i-t] == 1 || before != MAP[i-t][j])
            flag = 1;
          else
            P[i-t] = 1;
          if(flag)
            break;
        }
        before++;
      }
      if(flag)
        break;
    }
    // cout<<flag<<endl;
    if(flag == 0)
      Cnt++;
  }
}
int main(){
  scanf("%d%d",&N,&L );
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++)
      scanf("%d",&MAP[i][j] );
  }

  Cnt = 0;
  findRow();
  findCol();

  printf("%d\n",Cnt );
}
