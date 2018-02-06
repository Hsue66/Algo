#include<cstdio>

using namespace std; 

int Arr[1001];
int MAX[1001]={0};

int main(){
	int num;
	scanf("%d",&num);
	
	Arr[0] = 1001;
	for(int i=1; i<num+1; i++){
		scanf("%d",&Arr[i]);

		for(int j=0; j<i; j++){
			if(Arr[j] > Arr[i] && MAX[i] < MAX[j]+1)
				MAX[i] = MAX[j]+1;
		}
	}

	int max=0;
	for(int i=1; i<num+1; i++){
		if(max < MAX[i])
			max = MAX[i];
	//	cout<<MAX[i]<<" ";
	}
	printf("%d\n",max);
}
