#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int D,W,K;
int MAP[13][20];
int Min;
queue<vector<pair<int,int> > > Queue;

bool scan(int map[13][20]){
  int flag =0;
  for(int j=0; j<W && flag == j; j++){
    int cnt0,cnt1;
    cnt0 = cnt1 = 0;
    for(int i=0; i<D; i++){
      if(map[i][j] == 1){
        cnt1++;
        cnt0 = 0;
      }else{
        cnt0++;
        cnt1 = 0;
      }
      if(cnt0 == K || cnt1 == K){
        flag++;
        break;
      }
    }
  }
  if(flag == W)
    return true;
  else
    return false;
}

void useD(){
  int flag = 0;
  int size = 0;
  while(!Queue.empty() && flag == 0){
    int map[13][20];
    for(int i=0; i<D; i++)
      copy(MAP[i],MAP[i]+W,map[i]);

    vector<pair<int,int> > changed = Queue.front();
    size = changed.size();
    Queue.pop();

    // change map
    int idx;
    for(int i=0; i<size; i++){
      idx = changed[i].first;
//      cout<<idx<<" ";
      int val = changed[i].second;
      fill_n(map[idx],W,val);
    }
//    cout<<endl;
    if(scan(map)){
      flag = 1;
      Min = size;
//      cout<<"-----------"<<endl;
      break;
    }
    else{
      for(int i= idx+1; i<D; i++){
        changed.push_back(make_pair(i,0));
        Queue.push(changed);
        changed.pop_back();
        changed.push_back(make_pair(i,1));
        Queue.push(changed);
        changed.pop_back();
      }
    }
  }
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  for(int t=1; t<=testcase; t++){
    scanf("%d%d%d",&D,&W,&K );
    for(int i=0; i<D; i++){
      for(int j=0; j<W; j++)
        scanf("%d",&MAP[i][j] );
    }

    Min = W;
    if(scan(MAP))
      Min = 0;
    else{
      for(int i=0; i<D; i++){
        vector<pair<int,int> > temp;
        temp.push_back(make_pair(i,0));
        Queue.push(temp);
        temp.pop_back();
        temp.push_back(make_pair(i,1));
        Queue.push(temp);
      }
      useD();
    }
    while(!Queue.empty())
      Queue.pop();
    printf("#%d %d\n",t,Min);
  }
}
