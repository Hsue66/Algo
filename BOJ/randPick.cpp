#include<cmath>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<chrono>
#include<random>

using namespace std;

int main(){
	vector<string> slist;
	string temp;
	while(1){
		cin>>temp;
		if(temp =="0")
			break;
		slist.push_back(temp);
	}
	
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	
	shuffle(begin(slist), end(slist), default_random_engine(seed));

	for(int i=0; i<slist.size(); i++){
		if(i%3==0)
			cout<<endl;

		cout<<slist[i]<<" ";
	}

}
