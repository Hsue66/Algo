#include<cstdio>
#include<cmath>
//#include<iostream>

using namespace std;

int Store[100001];

int main(){
	int num;
	scanf("%d",&num);

	Store[0] = 0;
	Store[1] = 1;
	Store[2] = 2;
	Store[3] = 3;

	for(int i=4; i < num+1; i++){
		Store[i] = i;
		for(int j=1; j*j<=i; j++){
			if(Store[i] > Store[i-(j*j)]+1)
				Store[i] = Store[i-(j*j)] + 1;
		}
	}
	printf("%d\n",Store[num]);
}
