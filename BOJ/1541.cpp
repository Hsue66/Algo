#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

string str;

pair<int, int> findNum(int start){
	int num = 0;
	int i = start;
	for(; i<str.length(); i++){
		if(str[i] == '-' || str[i] == '+')
			break;
		num = num*10 + (str[i]-'0');
	}
	return make_pair(num, i);
}

int main(){
	cin>> str;

	pair<int,int> val = findNum(0);	
	int sum = val.first;
	int start = val.second;
	int flag = 0;

	while(start != str.length()){
		val = findNum(start+1);
		if(str[start] == '-'){
			flag = 1;
			sum -= val.first;	
		}else{
			if(flag)
				sum -= val.first;
			else
				sum += val.first;
		}
		start = val.second;
	}
	printf("%d",sum);
}
