#include<cstdio>
#include<queue>
//#include<iostream>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	priority_queue <int, vector<int>, greater<int> > pq;
	while(n--){
		int temp;
		scanf("%d",&temp);
		pq.push(temp);
	}
	while(!pq.empty()){
		printf("%d\n",pq.top());
		pq.pop();
	}
}
