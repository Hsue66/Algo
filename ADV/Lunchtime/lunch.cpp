#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

vector<pair<int,int> > Person;
vector<pair<pair<int,int>,int> > Stair;
int N,P,Min,last;

void downStair(vector<int> waits, int K){
  int cnt = 3;
  queue<int> out;
  int len = waits.size();
  int before = 0;
  for(int i=0; i<len; i++){
    int now = waits[i];
    if(before > now)
      now = before;
    //cout<<cnt<<": "<<now<<" ";
    if(cnt > 0){
      cnt--;
      //cout<<"->"<<now+K<<endl;
      out.push(now+K);
    }else{
      while(!out.empty() && now < out.front())
        now++;
      before = now;
      //cout<<"out: ";
      while(!out.empty() && out.front() <= now){
        //cout<<out.front()<<" ";
        out.pop();
        cnt++;
      }
      cnt--;
      out.push(now+K);
      //cout<<"->"<<now+K<<endl;
      //cout<<cnt<<endl;
    }
  }
  while(!out.empty()){
    last = out.front();
    out.pop();
  }
}

void findTime(vector<int> G, int s){
  int len = G.size();
  for(int i=0; i<len; i++)
    G[i] = abs(Person[G[i]].first - Stair[s].first.first)+abs(Person[G[i]].second - Stair[s].first.second)+1;

  sort(G.begin(), G.end());
  downStair(G,Stair[s].second);
}

void moveToS(int c){
  vector<int> q;
  for(int i=1; i<=c; i++)
    q.push_back(1);
  for(int i=c; i<P; i++)
    q.push_back(0);
  sort(q.begin(),q.end());

  do{
    vector<int> A,B;
    for(int i=0; i<P; i++){
      if(q[i] == 1)
        A.push_back(i);
      else
        B.push_back(i);
    }
    findTime(A,0);
    int temp = last;
    findTime(B,1);
    temp = max(last,temp);
    Min = min(temp,Min);

    findTime(A,1);
    temp = last;
    findTime(B,0);
    temp = max(last,temp);
    Min = min(temp,Min);
  }while(next_permutation(q.begin(),q.end()));
}


int main(){
  // vector<int> A,B;
  // A.push_back(3);
  // A.push_back(4);
  // A.push_back(4);
  // downStair(A,5);
  int testcase;
  scanf("%d",&testcase);
  for(int t=0; t<testcase; t++){
    scanf("%d",&N );
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        int t;
        scanf("%d",&t);
        if(t == 1)
          Person.push_back(make_pair(i,j));
        else if(t >= 2)
          Stair.push_back(make_pair(make_pair(i,j),t));
      }
    }

    P = Person.size();
    Min = 987654321;
    for(int i=1; i<=P; i++)
      moveToS(i);

    printf("#%d %d\n",t+1,Min );
    Person.clear();
    Stair.clear();
  }
}
