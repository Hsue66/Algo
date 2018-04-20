#include<cstdio>
//#include<iostream>
#define MAX 1000000000;

using namespace std;

int D[201][201] = {0};

int search(int k, int value){
	long long sum = 0;
	if(k-1 != 0){
		for(int i = value; i >= 0; i--){
			if(D[k-1][i] == 0)
				sum += search(k-1,i);
			else
				sum += D[k-1][i];
			sum = sum % MAX;
		}
		D[k][value] = sum;
	}
	return D[k][value];
}

int main(){
	int N,K;
	scanf("%d%d",&N,&K);

	for(int i=0; i<201; i++){
		D[1][i] = 1;
		D[i][0] = 1;
	}
	
	printf("%d\n",search(K,N));
}
