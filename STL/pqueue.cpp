#include<iostream>
#include<queue>

using namespace std;

int main(){
  priority_queue<int> pq;
  priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq2;
  pq.push(3);
  pq.push(0);
  pq.push(10);

  pq2.push(make_pair(3,make_pair(0,1)));
  pq2.push(make_pair(0,make_pair(0,1)));
  pq2.push(make_pair(10,make_pair(0,1)));

  while(!pq2.empty()){
    cout<<pq2.top().first<<" ";
    pq2.pop();
  }
  cout<<endl;
}
