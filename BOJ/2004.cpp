#include<cstdio>
//#include<iostream>

using namespace std;

int main(){
	long long n,m;
	scanf("%lld%lld",&n,&m);
	
	long long cntTWO = 0;
	long long cntFIVE = 0;
	if(m==0 || n==m)
		printf("0\n");
	else{
		//분자
		for(long long i=5; i<=n; i*=5)
			cntFIVE += n/i;
		for(long long i=2; i<=n; i*=2)
			cntTWO += n/i;
		//분모
		for(long long i=5; i<=m; i*=5)
			cntFIVE -= m/i;
		for(long long i=2; i<=m; i*=2)
			cntTWO -= m/i;
		//분모
		for(long long i=5; i<=(n-m); i*=5)
			cntFIVE -= (n-m)/i;
		for(long long i=2; i<=(n-m); i*=2)
			cntTWO -= (n-m)/i;

		if(cntTWO<cntFIVE)
			printf("%lld\n",cntTWO);
		else
			printf("%lld\n",cntFIVE);
	}
}
