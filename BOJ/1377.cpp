#include<cstdio>
#include<vector>
#include<algorithm>
//#include<iostream>

using namespace std;

int a[500001];

int main(){
	int n;
	scanf("%d",&n);

	vector<pair<int,int> > a(n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}

	sort(a.begin(),a.end());

	int max = 0;
	for(int i =0; i<n; i++){
		int diff = a[i].second - i;
		if(max <diff)
			max = diff;
	}

	printf("%d\n",max+1);	
}
