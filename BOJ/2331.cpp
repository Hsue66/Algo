#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>

using namespace std;

int deg;
int len = 0;
vector<int> G;

int calc(int num){
	int sum=0;
	do{
		int temp = num%10;
		sum += pow(temp,deg);
		num = num/10;
	}while(num%10 >0 || num/10 >0);
	return sum;
}

int check(int num){
	for(int i=0; i<len; i++)
		if(G[i] == num)
			return i;
	return -1;
}

void makeG(int now){
	int nex = calc(now);
	//cout<<nex<<" ";
	int comp = check(nex);
	if(comp == -1){
		G.push_back(nex);
		len++;
		makeG(nex);
	}
	else
		printf("%d\n",comp);
}

int main(){
	int now;
	scanf("%d%d",&now,&deg);
	
	G.push_back(now);
	len++;
	makeG(now);
}
