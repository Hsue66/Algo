#include<cstdio>
#include<vector>
#include<cmath>
//#include<iostream>
#define MAX 1000000

using namespace std;

int P;
int cnt[MAX];

int calc(int num){
	int value=0;
	do{
		value += pow(num%10,P);
		num = num/10;
	}while(num != 0);

	return value;
}

void find(int Num){
	int next = calc(Num);
	if(cnt[next] == 0){
		cnt[next] = cnt[Num] +1;
		find(next);
	}
	else
		printf("%d\n",cnt[next]-1);
}

int main(){
	int Num;
	scanf("%d%d",&Num,&P);

	cnt[Num] = 1;
	find(Num);
}
