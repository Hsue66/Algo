#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int N,M,C,Max;
int MAP[10][10];
vector<pair<pair<int,int>,int> > possible;
int TEMP[5];

void find(int cnt){
  vector<int> p;
  for(int i=0; i<cnt; i++)
    p.push_back(1);
  for(int i=0; i<M-cnt; i++)
    p.push_back(0);

  sort(p.begin(),p.end());
  do{
    int sum = 0;
    int cand = 0;
    for(int i=0; i<M; i++){
      if(p[i] == 1){
        sum += TEMP[i];
        cand += pow(TEMP[i],2);
      }
    }
    if(sum <= C)
      Max = max(Max, cand);
  }while(next_permutation(p.begin(),p.end()));
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=0; t<testcase; t++){
    scanf("%d%d%d",&N,&M,&C );
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++)
        scanf("%d",&MAP[i][j] );
    }

    for(int i=0; i<N; i++){
      for(int j=0; j<=N-M; j++)
        possible.push_back(make_pair(make_pair(i,j),0));
    }

    int psize = possible.size();
    for(int i=0; i<psize; i++){
      pair<int,int> pos = possible[i].first;
      int nx = pos.first;
      int ny = pos.second;
      for(int t=0; t<M; t++)
        TEMP[t] = MAP[nx][ny+t];

      Max = 0;
      for(int c=1; c<=M; c++)
        find(c);
      possible[i] = make_pair(pos,Max);
      //cout<<Max<<endl;
    }

    Max = 0;
    for(int i=0; i<psize-1; i++){
      int sum = possible[i].second;
      int nx = possible[i].first.first;
      int ny = possible[i].first.second;
      for(int j=i+1; j<psize; j++){
        int tx = possible[j].first.first;
        int ty = possible[j].first.second;
        if(tx == nx){
          if(ty < ny+M)
            continue;
        }
        Max = max(Max,sum+possible[j].second);
      }
    }

    printf("#%d %d\n",t+1, Max );
    possible.clear();
  }
}
