#include<cstdio>
//#include<iostream>

using namespace std;

long long Parr[100] = {0};

int main(){
	int num;
	scanf("%d",&num);

	Parr[0] = 1; 
	Parr[1] = 1; 
	Parr[2] = 1; 

	for(;num>0; num--){
		int now;
		scanf("%d",&now);
		
		for(int i=0; i<now; i++){
			if(Parr[i] == 0)
				Parr[i] = Parr[i-3]+Parr[i-2];
		//	cout<<Parr[i]<<" ";
		}
		//cout<<endl;

		printf("%lld\n",Parr[now-1]);
	}	
}
