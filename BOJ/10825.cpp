#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

struct Person{
	int kor;
	int eng;
	int math;
	string name;
};

bool cmp(const Person &u, const Person &v){
	 if(u.kor == v.kor){
		if(u.eng == v.eng){
			 if(u.math == v.math)
				 return u.name < v.name;
			 else
				 return u.math > v.math;
		}
		else
			return u.eng < v.eng;
	 }
	 else
		 return u.kor > v.kor;
}

int main(){
	int n;
	scanf("%d",&n);

	vector<Person> p(n);
	for(int i=0; i<n; i++)
		cin>> p[i].name >> p[i].kor >>p[i].eng >> p[i].math;

	sort(p.begin(),p.end(), cmp);

	for(int i=0; i<n; i++)
		cout<<p[i].name<<'\n';
}


