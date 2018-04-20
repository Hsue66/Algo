#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
#include<iostream>

using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	vector<tuple<int,int,int,string> > P(N);
	for(int i=0; i<N; i++){
		string name;
		int kor, eng, math;
		cin>>name>>kor>>eng>>math;
		P[i] = make_tuple(-kor,eng,-math,name);
	}

	sort(P.begin(),P.end());
	for(int i=0; i<N; i++)
		cout<<get<3>(P[i])<<"\n";
}
