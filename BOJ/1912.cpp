#include<cstdio>
#include<iostream>

using namespace std;

int SUM[100000];

int main(){
	int num;
	scanf("%d",&num);
	
	SUM[0] = 0;
	for(int i=1; i<num+1; i++){
		int now;
		scanf("%d",&now);
		SUM[i] = max(now+SUM[i-1],now);
	}

	int max = SUM[1];
	for(int i=2; i<num+1; i++){
		if(SUM[i] > max)
			max = SUM[i];
	//	cout<<SUM[i]<<" ";
	}

	printf("%d\n",max);
}
