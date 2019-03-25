#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int N;
int MAP[20][20];
pair<int,int> sharkP;
vector<pair<int,int> > eatable;

int main(){
  eatable.push_back(make_pair(3,2));
  eatable.push_back(make_pair(1,5));
  eatable.push_back(make_pair(1,1));
  eatable.push_back(make_pair(2,2));
  eatable.push_back(make_pair(1,2));
  eatable.push_back(make_pair(3,1));

  cout<<"eatable"<<endl;
 for(int i=0; i<eatable.size(); i++)
   cout<<eatable[i].first<<" "<<eatable[i].second<<endl;

   sort(eatable.begin(), eatable.end());

  cout<<endl;
  for(int i=0; i<eatable.size(); i++)
    cout<<eatable[i].first<<" "<<eatable[i].second<<endl;


}


// cout<<"-----------------------"<<endl;
// cout<<Time<<endl;
// for(int i=0; i<N; i++){
//   for(int j=0; j<N; j++)
//   cout<<MAP[i][j]<<" ";
//   cout<<endl;
// }
// cout<<sharkP.first<<" "<<sharkP.second<<endl;
//
// cout<<"eatable"<<endl;
// for(int i=0; i<eatable.size(); i++)
//   cout<<eatable[i].first<<" "<<eatable[i].second<<endl;
//
// cout<<"bigfish "<<bigfish.size()<<endl;
// for(int i=0; i<bigfish.size(); i++)
//   cout<<bigfish[i].second.first<<" "<<bigfish[i].second.second<<endl;
//
//   int a;
// cin>>a;
