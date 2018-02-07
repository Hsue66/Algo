#include<cstdio>
#include<iostream>

using namespace std;

int SUM[3][300];

int main(){
	int num;
	scanf("%d",&num);
	
	SUM[0][0] = 0;
	SUM[2][0] = 0;
	scanf("%d",&SUM[1][0]);

	for(int i=1; i<num; i++){
		int now;
		scanf("%d",&now);
		// 0
		SUM[0][i] = max(SUM[1][i-1],SUM[2][i-1]);
		/*for(int t=1; t<3; t++){
			if(SUM[0][i]< SUM[t][i-1])
				SUM[0][i] = SUM[t][i-1];
		}*/

		// 1
		SUM[1][i] = SUM[0][i-1]+ now;

		// 2
		SUM[2][i] = SUM[1][i-1]+ now;
	}
/*
	for(int i=0; i<3; i++){
		for(int j=0; j<num; j++)
			cout<<SUM[i][j]<<" ";
		cout<<endl;
	}
*/
	printf("%d\n",max(SUM[1][num-1],SUM[2][num-1]));
}
