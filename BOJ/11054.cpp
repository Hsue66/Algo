#include<cstdio>

using namespace std; 

int Arr[1001];
int LtoR[1001]={0};
int RtoL[1001]={0};

int main(){
	int num;
	scanf("%d",&num);
	
	Arr[0] = 0;
	int end = num+1;
	Arr[end] = 0;

	for(int i=1; i<num+1; i++)
		scanf("%d",&Arr[i]);
	
	for(int i=1; i<num+1; i++){
		for(int j=0; j<i; j++){
			if(Arr[j] < Arr[i] && LtoR[i] < LtoR[j]+1)
				LtoR[i] = LtoR[j]+1;
			if(Arr[end-j] < Arr[end-i] && RtoL[end-i] < RtoL[end-j]+1)
				RtoL[end-i] = RtoL[end-j]+1;
		}
	}

	int max=0;
	for(int i=1; i<num+1; i++){
		int sum = LtoR[i]+RtoL[i]-1;
		if(max < sum)
			max = sum;
	//	cout<<MAX[i]<<" ";
	}
	printf("%d\n",max);
}
