#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<queue>

using namespace std;

int N,W,H,Min;
int MAP[15][12];
// int Ori[4][15][12];
int Dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
vector<pair<pair<int,int>,int> > TopB(12);
set<pair<int,int> > Remove;

void spread(int x, int y, int range){
  if(Remove.find(make_pair(x,y)) == Remove.end()){
    Remove.insert(make_pair(x,y));
    MAP[x][y] = 0;
  }
  for(int d=0; d<4; d++){
    int tx = x;
    int ty = y;
    for(int r=range-1; r>0; r--){
      tx += Dir[d][0];
      ty += Dir[d][1];
      if(0<= tx && tx < H && 0<= ty && ty < W){
        if(Remove.find(make_pair(tx,ty)) == Remove.end()){
          Remove.insert(make_pair(tx,ty));
          spread(tx,ty,MAP[tx][ty]);
          MAP[tx][ty] = 0;
        }
      }else
        break;
    }
  }
}

void dropBall(int idx){
  int x = TopB[idx].first.first;
  int y = TopB[idx].first.second;
  int range = TopB[idx].second;
  spread(x,y,range);
}

void Rebuild(){
  for(int j=0; j<W; j++){
    queue<int> q;
    for(int i=H-1; i>=0; i--){
      if(MAP[i][j] != 0){
        q.push(MAP[i][j]);
        MAP[i][j] = 0;
      }
    }
    int idx = H-1;
    if(q.empty())
      TopB[j] = make_pair(make_pair(-1,-1),-1);
    while(!q.empty()){
      TopB[j] = make_pair(make_pair(idx,j),q.front());
      MAP[idx][j] = q.front();
      idx--;
      q.pop();
    }
  }
}
void show(){
  cout<<"show---"<<endl;
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++)
      cout<<MAP[i][j]<<" ";
      cout<<endl;
  }
  cout<<endl;
}

int count(){
  int cnt = 0;
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(MAP[i][j] != 0)
        cnt++;
    }
  }
  return cnt;
}

void Select(int times){
  if(times == N){
    // cout<<"END"<<endl;
    Min = min(Min, count());
    // char a;
    // cin>>a;
  }else{
    int Ori[15][12];
    vector<pair<pair<int,int>,int> > topB(12);
    for(int i=0; i<H; i++)
      copy(MAP[i],MAP[i]+W,Ori[i]);
    for(int i=0; i<12; i++)
      topB[i] = TopB[i];

    for(int idx=0; idx<W; idx++){
      // cout<<idx<<endl;
      Remove.clear();
      if(TopB[idx].second != -1){
        dropBall(idx);
        Rebuild();
      }
      // show();
      Select(times+1);
      for(int i=0; i<H; i++)
        copy(Ori[i],Ori[i]+W,MAP[i]);
      for(int i=0; i<12; i++)
        TopB[i] = topB[i];
    }
  }
}
int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=0; t<testcase; t++){
    scanf("%d%d%d",&N,&W,&H );
    for(int i=0; i<H; i++){
      for(int j=0; j<W; j++){
        scanf("%d",&MAP[i][j] );
        if((MAP[i][j] != 0 && i==0)||(MAP[i][j] != 0 && MAP[i-1][j] == 0))
          TopB[j] = make_pair(make_pair(i,j),MAP[i][j]);
      }
    }

    Min = W*H+1;
    Select(0);
    printf("#%d %d\n",t+1,Min );
  }
}
