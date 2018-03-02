#include<cstdio>
#include<iostream>

#define DIV 1000000000

using namespace std;
int cnt, num;
int Arr[201][201]={0};

int find(int c, int n){
	int result = 0;

	if(c-1 == 0){
		Arr[c][n] = 1;
		return Arr[c][n];
	}

	for(int i=0; i<=n; i++){
		if(Arr[c-1][i] == 0 )
			Arr[c-1][i] = find(c-1,i);
		long long temp = result + Arr[c-1][i];
		result = temp % DIV;
	}

	return result;
}

int main(){
	scanf("%d%d",&num,&cnt);
	
	cout<<find(cnt,num)<<endl;
}
