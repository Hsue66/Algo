#include<cstdio>
//#include<iostream>

using namespace std; 

int Arr[1001];
int SUM[1001]={0};

int main(){
	int num;
	scanf("%d",&num);
	
	Arr[0] = 0;
	for(int i=1; i<num+1; i++){
		scanf("%d",&Arr[i]);

		for(int j=0; j<i; j++){
			if(Arr[j] < Arr[i] && SUM[i] < SUM[j]+Arr[i])
				SUM[i] = SUM[j]+Arr[i];
		}
	}

	int max=0;
	for(int i=1; i<num+1; i++){
		if(max < SUM[i])
			max = SUM[i];
		//cout<<SUM[i]<<" ";
	}
	printf("%d\n",max);
}
