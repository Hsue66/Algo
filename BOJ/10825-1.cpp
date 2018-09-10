#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

struct Person{
  string name;
  int ko;
  int eng;
  int math;
};

bool cmp(const Person &p1, const Person &p2){
  if(p1.ko == p2.ko){
    if(p1.eng == p2.eng){
      if(p1.math == p2.math)
        return p1.name < p2.name;
      else
        return p1.math > p2.math;
    }
    else
      return p1.eng < p2.eng;
  }
  else
    return p1.ko > p2.ko;
}

int main(){
  int N;
  scanf("%d",&N);
  vector<Person> People(N);
  for(int i=0; i<N; i++){
    cin>>People[i].name;
    scanf("%d%d%d",&People[i].ko, &People[i].eng, &People[i].math);
  }
  sort(People.begin(),People.end(), cmp);

  for(int i=0; i<N; i++){
    cout<<People[i].name;
    printf("\n");
  }
}
