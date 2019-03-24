#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

vector<pair<pair<int,int>,vector<int> > > LiveT;
int A[10][10];
int Earth[10][10];

int N,M,K;

int main(){

  vector<int> a;

  vector<pair<pair<int,int>,vector<int> > >  L;
  vector<int> t;
  t.push_back(1);
  L.push_back(make_pair(make_pair(1,2),t));

  for(int i=0; i<L.size(); i++){
    int len = L[i].second.size();
    for(int j=0; j<len; j++)
      cout<<L[i].second.at(j)<<" ";
  }
  cout<<endl;
  t.push_back(3);
  t.push_back(5);

  for(int i=0; i<L.size(); i++)
    L[i] = make_pair(L[i].first,t);

    for(int i=0; i<L.size(); i++){
      int len = L[i].second.size();
      for(int j=0; j<len; j++)
        cout<<L[i].second.at(j)<<" ";
    }
    cout<<"---------"<<endl;
    for(int i=0; i<3; i++)
      t.push_back(1);
  for(int i=0; i<t.size(); i++)
    cout<<t[i]<<" ";
    cout<<endl;
  // queue<pair<pair<int,int>, queue<int> > > T;
  // queue<int> q;
  // q.push(3);
  // T.push(make_pair(make_pair(1,2),q));
  //
  // vector<int> a;
  // a.push_back(3);
  // a.push_back(2);
  // a.push_back(1);
  // a.push_back(5);
  // for(int i=0; i<a.size(); i++)
  //   cout<<a[i]<<endl;
  //   sort(a.begin(),a.end());
  // for(int i=0; i<a.size(); i++)
  //   cout<<a[i]<<endl;

//   vector<int> > > L;
//   vector<int> t;
//   t.push_back(1);
//   L.push_back(make_pair(make_pair(1,2),t));
//
//   vector<pair<pair<int,int>, vector<int> > > M;
//   for(int i=0; i<L.size(); i++){
//     pair<int,int> pos = L[i].first;
//     cout<<pos.first <<" "<<pos.second<<endl;
//     vector<int> Ts = L[i].second;
//     for(int t=0; t<Ts.size(); t++ ){
//       cout<<Ts[t]<<endl;
//       Ts[t]++;
//     }
//
//     for(int t=0; t<Ts.size(); t++ ){
//       cout<<Ts[t]<<" "<<L[i].second.at(t);
//       //Ts[t]++;
//     }
//     M.push_back(make_pair(pos,Ts));
//   }
//   L = M;
// cout<<endl;
//   for(int i=0; i<L.size(); i++){
//     vector<int> Ts = L[i].second;
//     for(int t=0; t<Ts.size(); t++ ){
//       cout<<Ts[t]<<endl;
//     }
}
