#include<iostream>
#include<cstdio>
#include<list>
#include<vector>

using namespace std;

int N;
vector<pair<long long, long long> > Input;

bool cmp(const pair<long long, long long> &i1,pair<long long, long long> &i2){
	return i1.second > i2.second;
}

int main(){

	scanf("%d",&N);

	for(int i=0; i<N; i++){
		long long ts,te;
		scanf("%lld%lld",&ts,&te);
		Input.push_back(make_pair(ts,te));
	}

	sort(Input.begin(),Input.end(),cmp);

	for(int i=0; i<N; i++)
		cout<<"<"<<Input[i].first<<" "<<Input[i].second<<"> ";
	cout<<endl;
}
