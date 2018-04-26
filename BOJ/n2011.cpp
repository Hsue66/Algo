#include<cstdio>
#include<string>
#include<iostream>
#define DIV 1000000
using namespace std;

string code;
int sum[5002];

void count(){
	for(int i=1; i<code.size(); i++){
		if(code[i]-'0' >= 1)
			sum[i] = (sum[i] + sum[i-1]) % DIV;

		int temp = (code[i-1]-'0')*10 + (code[i]-'0');
	
		if(10 <= temp && temp < 27)
			sum[i] = (sum[i] + sum[i-2]) % DIV;
	}
}

int main(){
	cin>>code;
	sum[0] = 1;
	code = ' '+code;

	count();

	printf("%d\n",sum[code.size()-1]);
}
