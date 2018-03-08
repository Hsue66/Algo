#include<cstdio>
#include<iostream>

using namespace std;

string save[8] = {"000","001","010","011","100","101","110","111"};

int main(){
	string oct;
	cin >> oct;

	int len = oct.length();

	for(int i=0; i<len; i++){
		if(i==0){
			string temp = save[oct[i]-'0'];
			int idx=0;
			while(temp[idx++]=='0' && idx < 3);
			for(int t = idx-1; t<3; t++)
				printf("%c",temp[t]);
		}
		else
			cout<<save[oct[i]-'0'];
	}
	
	printf("\n");
}
