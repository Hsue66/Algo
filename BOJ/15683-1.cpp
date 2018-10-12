#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#define LIMIT 9

using namespace std;
int N,M;
int MAP[LIMIT][LIMIT];
vector<pair<int,pair<int,int> > > CCTV;
vector<pair<int,int> > CCTV5;
int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
int Min = 987654321;


stack<pair<int,int> > cover(int cx, int cy,int idx){
  int x = cx;
  int y = cy;
  stack<pair<int,int> > S;
  while(1){
    x = x+dir[idx][0];
    y = y+dir[idx][1];
    if(x<0 || y<0 || N <= x || M <= y || MAP[x][y] == 6)
      break;
    if(MAP[x][y] == 0)
      S.push(make_pair(x,y));
    MAP[x][y] = 7;
  }
  return S;
}

void search(int idx){
  if(idx < CCTV.size()){
    int type = CCTV[idx].first;
    int cx = CCTV[idx].second.first;
    int cy = CCTV[idx].second.second;

    if(type == 1){
      for(int i=0; i<4; i++){
        stack<pair<int,int> > S = cover(cx,cy,i);
        search(idx+1);
        while(!S.empty()){
          //cout<<S.top().first<<","<<S.top().second<<endl;
          MAP[S.top().first][S.top().second] = 0;
          S.pop();
        }
      }
    }else if(type == 2){
      for(int i=0; i<2; i++){
        stack<pair<int,int> > S = cover(cx,cy,i);
        stack<pair<int,int> > S2 = cover(cx,cy,i+2);
        search(idx+1);
        while(!S.empty()){
          MAP[S.top().first][S.top().second] = 0;
          S.pop();
        }
        while(!S2.empty()){
          MAP[S2.top().first][S2.top().second] = 0;
          S2.pop();
        }
      }
    }else if(type == 3){
      for(int i=0; i<4; i++){
        stack<pair<int,int> > S = cover(cx,cy,i);
        stack<pair<int,int> > S2 = cover(cx,cy,(i+1)%4);
        search(idx+1);
        while(!S.empty()){
          MAP[S.top().first][S.top().second] = 0;
          S.pop();
        }
        while(!S2.empty()){
          MAP[S2.top().first][S2.top().second] = 0;
          S2.pop();
        }
      }
    }else{
      for(int i=0; i<4; i++){
        stack<pair<int,int> > S = cover(cx,cy,i);
        stack<pair<int,int> > S1 = cover(cx,cy,(i+1)%4);
        stack<pair<int,int> > S2 = cover(cx,cy,(i+2)%4);
        search(idx+1);
        while(!S.empty()){
          MAP[S.top().first][S.top().second] = 0;
          S.pop();
        }
        while(!S1.empty()){
          MAP[S1.top().first][S1.top().second] = 0;
          S1.pop();
        }
        while(!S2.empty()){
          MAP[S2.top().first][S2.top().second] = 0;
          S2.pop();
        }
      }
    }
  }else{
    int Cnt = 0;
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        if(MAP[i][j] == 0)
          Cnt++;
      }
    }
    Min = min(Cnt, Min);
    /*cout<<Cnt<<endl;
    char a;
    cin>>a;*/
  }
}

int main(){
  scanf("%d%d",&N,&M);
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%d",&MAP[i][j]);
      if( 0 < MAP[i][j] && MAP[i][j] < 5)
        CCTV.push_back(make_pair(MAP[i][j],make_pair(i,j)));
      if(MAP[i][j] == 5)
        CCTV5.push_back(make_pair(i,j));
    }
  }

  for(int i=0; i<CCTV5.size(); i++){
    cover(CCTV5[i].first,CCTV5[i].second,0);
    cover(CCTV5[i].first,CCTV5[i].second,1);
    cover(CCTV5[i].first,CCTV5[i].second,2);
    cover(CCTV5[i].first,CCTV5[i].second,3);
  }

  search(0);
  printf("%d\n",Min);
}
