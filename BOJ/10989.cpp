#include<cstdio>
//#include<iostream>

using namespace std;


int main(){
	int n;
	scanf("%d",&n);
	
	int VAL[10001]={0};
	for(int i=0; i<n; i++){
		int temp;
		scanf("%d",&temp);
		VAL[temp]++;
	}
		
	for(int i=0; i<10001; i++){
		for(int j=0; j<VAL[i]; j++)
			printf("%d\n",i);
	}
}


