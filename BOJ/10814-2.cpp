#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

struct Person{
	int age;
	string name;
	int id;
};

int main(){
	int n;
	scanf("%d",&n);

	vector<Person> p(n);
	for(int i=0; i<n; i++){
		cin>> p[i].age >> p[i].name;
		p[i].id = i;	
	}

	sort(p.begin(),p.end(), [](Person u, Person v) {
		return (u.age < v.age) || (u.age == v.age && u.id < v.id);
	});
  
	for(int i=0; i<n; i++)
		cout<<p[i].age <<" "<<p[i].name<<endl;
}
