#include<iostream>
#include<cstdio>
#include<vector>
#include<set>

using namespace std;

int R,C,T;
int Air[2];
int Dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int rot[2][4] = {{2,1,0,3},{0,1,2,3}};
int Lim[2][2];
vector<pair<pair<int,int>, int> > Mise;
int New[50][50];

void spread(){
  int lenS = Mise.size();
  set<pair<int,int> > miseP;
  for(int i=0; i<lenS; i++){
    int oriV = Mise[i].second;
    int x = Mise[i].first.first;
    int y = Mise[i].first.second;
    int val = oriV/5;
    for(int t=0; t<4 && val!=0; t++){
      int tx = x+Dir[t][0];
      int ty = y+Dir[t][1];
      if(0<=tx && tx<R && 0<=ty && ty<C && New[tx][ty] != -1){
        New[tx][ty] += val;
        oriV -= val;
        if(!(tx == Air[0] || tx == Air[1] || tx == 0 || tx == R-1 || ty == 0 || ty == C-1 ))
          miseP.insert(make_pair(tx,ty));
      }
    }
    if(!(x == Air[0] || x == Air[1] || x == 0 || x == R-1 || y == 0 || y == C-1 ))
      miseP.insert(make_pair(x,y));
    New[x][y] += oriV;
  }

  vector<pair<pair<int,int>, int> > newMise;
  for(auto it=miseP.begin(); it!=miseP.end(); ++it){
    int i = (*it).first;
    int j = (*it).second;
    newMise.push_back(make_pair(make_pair(i,j),New[i][j]));
  }
  swap(Mise,newMise);
}

void circulate(int aIdx){
  int startX = Air[aIdx];
  int startY = 0;
  int idx = 0;
  int x = startX+Dir[rot[aIdx][idx]][0];
  int y = startY+Dir[rot[aIdx][idx]][1];
  while(!(x==startX && y==startY)){
    int tx = x+Dir[rot[aIdx][idx]][0];
    int ty = y+Dir[rot[aIdx][idx]][1];
    if(!(Lim[aIdx][0]<= tx && tx<Lim[aIdx][1] && 0<= ty && ty<C)){
      idx++;
      tx = x+Dir[rot[aIdx][idx]][0];
      ty = y+Dir[rot[aIdx][idx]][1];
    }

    New[x][y] = New[tx][ty];
    if(New[x][y] < 0)
      New[x][y] = 0;
    if(New[x][y] != 0)
      Mise.push_back(make_pair(make_pair(x,y),New[x][y]));
    x = tx;
    y = ty;
  }
}

int main(){
  scanf("%d%d%d",&R,&C,&T );
  int air = 0;
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      int t;
      scanf("%d",&t );
      if(t != 0){
        if(t == -1)
          Air[air++] = i;
        else
          Mise.push_back(make_pair(make_pair(i,j),t));
      }
    }
  }

  Lim[0][0] = 0;
  Lim[0][1] = Air[1];
  Lim[1][0] = Air[1];
  Lim[1][1] = R;
  while(T--){
    for(int i=0; i<R; i++)
      fill_n(New[i],C,0);
    New[Air[0]][0] = -1;
    New[Air[1]][0] = -1;
    spread();
    circulate(0);
    circulate(1);
  }
  int lenS = Mise.size();
  int sum = 0;
  for(int i=0; i<lenS; i++)
    sum += Mise[i].second;
  printf("%d\n",sum );
}
