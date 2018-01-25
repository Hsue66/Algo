#include<cstdio>
#include<iostream>

using namespace std;

long long Pinary[91];

int main(){
	int num;
	scanf("%d",&num);

	Pinary[0] = 0;
	Pinary[1] = 1;
	
	int index = 2;
	while(index < num+1){
		Pinary[index] = Pinary[index-1] + Pinary[index-2];
		index++;
	}

/*	for(int j=0 ; j<=num; j++)
		cout<<Pinary[j]<<" ";
	cout<<endl;
*/	

	printf("%lld\n",Pinary[num]);
	
}

