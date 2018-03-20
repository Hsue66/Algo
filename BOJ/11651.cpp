#include<cstdio>
#include<vector>
#include<algorithm>
//#include<iostream>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector<pair<int, int> > cordi;
	int t = n;
	while(t--){
		int tx,ty;
		scanf("%d%d",&tx,&ty);
		cordi.push_back(make_pair(ty,tx));
	}
	sort(cordi.begin(), cordi.end());

	for(int i=0; i<n; i++){ 
		printf("%d %d\n",cordi[i].second, cordi[i].first);
	}
}
