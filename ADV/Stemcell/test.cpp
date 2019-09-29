#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main(){
  vector<vector<int> > a;
  vector<int> b;
  vector<int> t(5,10);
  a.push_back(t);
  a.push_back(t);
  a.push_back(t);

  for(int i=0; i<a.size(); i++){
    for(int j=0; j<a[i].size(); j++)
      cout<<a[i][j]<<" ";
      cout<<endl;
  }

  cout<<"---------"<<endl;
  a[0].swap(b);
  for(int i=0; i<a.size()-1; i++)
    a[i].swap(a[i+1]);

  for(int i=0; i<a.size(); i++){
    for(int j=0; j<a[i].size(); j++)
      cout<<a[i][j]<<" ";
      cout<<endl;
  }
}
