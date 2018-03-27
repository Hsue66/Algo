#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

long long a[5000001];

int main(){
	int n,K;
	scanf("%d%d",&n,&K);
	K = K-1;

	for(int i=0; i<n; i++)
		scanf("%lld",&a[i]);
	
	nth_element(a,a+K,a+n);
	
	printf("%lld\n",a[K]);
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
