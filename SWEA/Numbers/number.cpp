#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N,Max,Min;
int Op[4],Num[12];
vector<int> p;

void calc(){
  sort(p.begin(),p.end());
  do{
    int sum = Num[0];
    for(int i=0; i<N-1; i++){
      switch (p[i]) {
        case 0:
          sum += Num[i+1];
          break;
        case 1:
          sum -= Num[i+1];
          break;
        case 2:
          sum *= Num[i+1];
          break;
        case 3:
          sum /= Num[i+1];
          break;
        default:
          break;
      }
    }
    Max = max(Max,sum);
    Min = min(Min,sum);
  }while(next_permutation(p.begin(),p.end()));
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=0; t<testcase; t++){
    scanf("%d",&N );
    for(int i=0; i<4; i++){
      scanf("%d",&Op[i] );
      for(int j=0; j<Op[i]; j++)
        p.push_back(i);
    }

    for(int i=0; i<N; i++)
      scanf("%d",&Num[i] );

    Min = 987654321;
    Max = -987654321;
    calc();

    int result = Max-Min;

    printf("#%d %d\n",t+1,result );
    p.clear();
  }
}
