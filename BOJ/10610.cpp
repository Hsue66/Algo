#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int num[11] = {0};
int main(){
	string str;
	cin>> str;

	int sum = 0;
	for(int i=0; i<str.length(); i++){
		int temp = str[i]-'0';
		num[temp]++;
		sum += temp;
	}

	if(sum%3 != 0 || num[0]==0)
		printf("-1");
	else{
		for(int i=9; i>=0; i--){
			for(int j=0; j<num[i]; j++)
				printf("%d",i);
		}
	}
	printf("\n");
}
