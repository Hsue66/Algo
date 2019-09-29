#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

vector<vector<int> > Battery;
int Dir[5][2] = {{0,0},{-1,0},{0,1},{1,0},{0,-1}};
int Path[2][100];
int Pos[2][2];
int M,A,Total;
vector<int> temp;

void check(int idx){
  temp.clear();
  for(int i=0; i<A; i++){
    int d = abs(Pos[idx][0]-Battery[i][0])+abs(Pos[idx][1]-Battery[i][1]);
    if( d <= Battery[i][2])
      temp.push_back(i);
  }
}

void move(int t){
  for(int i=0; i<2; i++){
    Pos[i][0] += Dir[Path[i][t]][0];
    Pos[i][1] += Dir[Path[i][t]][1];
  }
}

void passTime(){
  for(int t=0; t<=M; t++){
    vector<vector<int> > cand;
    for(int i=0; i<2; i++){
      check(i);
      cand.push_back(temp);
    }

    int idx[2] = {0};
    if(cand[0].size() > cand[1].size())
      idx[1] = 1;
    else
      idx[0] = 1;

    int big = cand[idx[0]].size();
    int small = cand[idx[1]].size();
    int choice[2];
    choice[0] = choice[1] = -1;
    int Max = 0;
    for(int i=0; i<big; i++){
      choice[idx[0]] = cand[idx[0]][i];
      for(int j=0; j<small; j++){
        choice[idx[1]] = cand[idx[1]][j];
        if(choice[0] == choice[1])
          Max = max(Max, Battery[choice[0]][3]);
        else
          Max = max(Max, Battery[choice[0]][3]+Battery[choice[1]][3]);
      }
      if(small == 0)
        Max = max(Max, Battery[choice[idx[0]]][3]);
    }
    Total += Max;
    if(t < M)
      move(t);
  }
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=0; t<testcase; t++){
    scanf("%d%d",&M,&A );
    for(int i=0; i<2; i++){
      for(int j=0; j<M; j++)
        scanf("%d",&Path[i][j] );
    }

    for(int i=0; i<A; i++){
      vector<int> temp(4);
      scanf("%d%d%d%d",&temp[1],&temp[0],&temp[2],&temp[3] );
      temp[0]--;
      temp[1]--;
      Battery.push_back(temp);
    }

    Pos[0][0] = Pos[0][1] = 0;
    Pos[1][0] = Pos[1][1] = 9;
    Total = 0;
    passTime();
    printf("#%d %d\n",t+1,Total);
    Battery.clear();
  }
}
