#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
	vector<string> suffix;
	vector<string>::iterator si;
	string str;
	getline(cin,str);
	for(int i=0; i<str.length(); i++)
		suffix.push_back(str.substr(i,str.length()));	

	sort(suffix.begin(), suffix.end());

	for(si=suffix.begin(); si<suffix.end(); si++)
		cout<<*si<<endl;
}
