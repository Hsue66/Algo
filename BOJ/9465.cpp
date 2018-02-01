#include<cstdio>
#include<iostream>

using namespace std;

int Arr[2][100000];
int Max[3][100000];
int Num;


void calcMax(){
	for(int i=1; i<Num+1; i++){
		// 0
		int max0 = Max[0][i-1];
		for(int t = 1; t<3; t++){
			if(max0 < Max[t][i-1])
				max0 = Max[t][i-1];
		}
		Max[0][i] = max0;

		int max1,max2;
		// 1
		max1 = Arr[0][i] + Max[0][i-1];
		max2 = Arr[0][i] + Max[2][i-1];
		if(max1 > max2)
			Max[1][i] = max1;
		else
			Max[1][i] = max2;
		
		// 2
		max1 = Arr[1][i] + Max[0][i-1];
		max2 = Arr[1][i] + Max[1][i-1];
		if(max1 > max2)
			Max[2][i] = max1;
		else
			Max[2][i] = max2;
	}
	
	int max = Max[0][Num-1];
	for(int t = 1; t<3; t++){
		if(max < Max[t][Num-1])
			max = Max[t][Num-1];
	}
	printf("%d\n",max);

/*
	for(int j=0; j<3; j++){
		for(int i=0; i<Num; i++)
			cout<<Max[j][i]<<" ";
		cout<<endl;
	}
	*/

}

int main(){
	int testcase;
	scanf("%d",&testcase);
	for(; testcase > 0; testcase--){
		scanf("%d",&Num);
		
		for(int j=0; j<2; j++){
			for(int i=0; i<Num; i++)
				scanf("%d",&Arr[j][i]);
		}

		Max[0][0] = 0;
		Max[1][0] = Arr[0][0];
		Max[2][0] = Arr[1][0];

		calcMax();

	}
}
