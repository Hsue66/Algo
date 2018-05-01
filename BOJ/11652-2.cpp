#include<cstdio>
#include<map>
#include<iostream>
using namespace std;

map<long long,int> MAP;
int N;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		long long temp;
		scanf("%lld",&temp);
		if(MAP.find(temp) != MAP.end())
			MAP[temp] = MAP[temp]+1;
		else
			MAP[temp] = 1;
	}

	int max = 0;
	long long idx = 0;
	for(auto it=MAP.begin(); it != MAP.end(); ++it){
		if((*it).second > max){
			max = (*it).second;
			idx = (*it).first;
		}
	}

	printf("%lld\n",idx);
}


