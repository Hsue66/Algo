#include<cstdio>
#include<iostream>

using namespace std;

int N,M,NM;

int main(){
	scanf("%d%d",&N,&M);
	NM = N-M;
	
	int cnt2=0, cnt5=0;
	int cnt10;

	if(!M || !NM)
		cnt10 = 0;
	else{
		for(long long num = 2; num <=N; num *= 2){
			cnt2 += N/num;
			if(num <= M)
				cnt2 -= M/num;
			if(num <= NM)
				cnt2 -= NM/num;
		}

		for(long long num = 5; num <=N; num *= 5){
			cnt5 += N/num;
			if(num <= M)
				cnt5 -= M/num;
			if(num <= NM)
				cnt5 -= NM/num;
		}

		cnt10 = min(cnt2,cnt5);
	}

	printf("%d\n",cnt10);
}
