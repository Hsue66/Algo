#include<cstdio>
//#include<iostream>
#define MAX 10100

using namespace std;

int main(){
	int N;
	int cnt[MAX]={0};
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		int temp;
		scanf("%d",&temp);
		cnt[temp]++;
	}

	for(int i=0; i<MAX; i++){
		while(cnt[i]--)
			printf("%d\n",i);
	}
}
