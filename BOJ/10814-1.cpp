#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Person{
  int age;
  char name[101];
};

bool cmp(Person p1, Person p2){
  return p1.age < p2.age;
}

int main(){
  int N;
  scanf("%d",&N );
  vector<Person> people(N);

  for(int i=0; i<N; i++)
    scanf("%d%s",&people[i].age, people[i].name);

  stable_sort(people.begin(),people.end(),cmp);

  for(int i=0; i<N; i++)
    printf("%d %s\n",people[i].age, people[i].name);
}
