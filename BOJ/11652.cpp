#include<cstdio>
#include<algorithm>
//#include<iostream>

using namespace std;


int main(){
	int n;
	scanf("%d",&n);
	
	long long a[1000001];
	for(int i=0; i<n; i++)
		scanf("%lld",&a[i]);
		
	sort(a,a+n);

	int max=1;
	long long val = a[0];
	long long before = a[0];
	int cnt = 1;	
	for(int i=1; i<n; i++){
		if(before == a[i])
			cnt++;
		else{
			if(max <cnt){
				max = cnt;
				val = before;
			}
			
			before = a[i];
			cnt = 1;
		}
	}
	if(max <cnt){
		max = cnt;
		val = before;
	}


	printf("%lld\n",val);
}


