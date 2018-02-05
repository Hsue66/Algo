#include<cstdio>
#include<iostream>

using namespace std; 

int MAX[3][10000];
int main(){
	int num;
	scanf("%d",&num);

	MAX[0][0] = 0;
	MAX[2][0] = 0;
	scanf("%d",&MAX[1][0]);

	for(int i=1; i < num; i++){
		int now;
		scanf("%d",&now);

		//0
		int max0 = MAX[0][i-1];
		for(int t=1; t<3; t++){
			if(MAX[t][i-1] > max0)
				max0 = MAX[t][i-1];
		}
		MAX[0][i] = max0;
		
		// 1
		MAX[1][i] = now + MAX[0][i-1];

		// 2
		MAX[2][i] = now + MAX[1][i-1];
		
	}
/*
	for(int i=0; i<num; i++){
		for(int j=0; j<3; j++)
			cout<<MAX[j][i]<<" ";
		cout<<endl;
	}
*/

	
	int max = MAX[0][num-1];
	for(int t=1; t<3; t++){
		if(MAX[t][num-1] > max)
			max = MAX[t][num-1];
	}
	printf("%d\n",max);

}
