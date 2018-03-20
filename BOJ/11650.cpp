#include<cstdio>
#include<vector>
#include<algorithm>
//#include<iostream>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector<pair<int, int> > cordi;
	//vector<pair<int, int> >::iterator iter;
	int t = n;
	while(t--){
		int tx,ty;
		scanf("%d%d",&tx,&ty);
		cordi.push_back(make_pair(tx,ty));
	}
	sort(cordi.begin(), cordi.end());

	for(int i=0; i<n; i++){ 
		printf("%d %d\n",cordi[i].first, cordi[i].second);
	}
}
