#include<cstdio>
#include<iostream>

using namespace std;

int NumberAscend[1001][10];

int main(){
	int num;
	scanf("%d",&num);

	for(int i =0; i<10; i++)
		NumberAscend[0][i] = 1;

	int index = 1;
	while(index < num+1){
		for(int i=0; i<10; i++){
			int sum = 0;
			for(int j=0; j<=i; j++)
				sum = (sum + NumberAscend[index-1][j]) % 10007;
			NumberAscend[index][i] = sum;
		}
		index++;
	}

	/*for(int j=0 ; j<num; j++){
		for(int i = 0; i<10; i++)
		cout<<NumberAscend[j][i]<<" ";
		cout<<endl;
	}*/
	

	int result = 0;
	for(int i = 0 ; i<10; i++)
		result = (result + NumberAscend[num-1][i])%10007;
	printf("%d\n",result);
	
}

