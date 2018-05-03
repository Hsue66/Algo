#include<cstdio>
#include<iostream>

using namespace std;

int N, cnt10;
int cnt2=0, cnt5=0;

int main(){
	scanf("%d",&N);

	for(int n=2; n<=N; n*=2)
		cnt2 += N/n;
	for(int n=5; n<=N; n*=5)
		cnt5 += N/n;
	cnt10 = min(cnt2,cnt5);

	printf("%d\n",cnt10);
}
