#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

int main(){
	string num;
	int	base;
	cin>>num;
	scanf("%d",&base);

	int sum = 0;
	int len = num.length();
	for(int i=0; i<len; i++){
		int now;
		if('A'<=num[i] && num[i]<='Z')
			now = num[i]-'A'+10;
		else
			now = num[i]-'0';

		sum += pow(base,len-1-i)*now;
	}
	printf("%d\n",sum);
}
