#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

struct Person{
	int age;
	string name;
};

bool cmp(const Person &u, const Person &v){
	return (u.age < v.age);
}

int main(){
	int n;
	scanf("%d",&n);

	vector<Person> p(n);
	for(int i=0; i<n; i++)
		cin>> p[i].age >> p[i].name;

	stable_sort(p.begin(),p.end(), cmp);

	for(int i=0; i<n; i++)
		cout<<p[i].age <<" "<<p[i].name<<endl;
}

