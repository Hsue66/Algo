#include<cstdio>
//#include<iostream>

using namespace std;

int main(){
	int num;
	scanf("%d",&num);
	
	int cntTWO = 0;
	int cntFIVE = 0;
	while(num--){
		int now = (num+1);
		//cout<<now<<endl;
		while(now%5 == 0){
			cntFIVE++;
			now = now/5;
		}
		while(now%2 == 0){
			cntTWO++;
			now = now/2;
		}
	}
	if(cntTWO<cntFIVE)
		printf("%d\n",cntTWO);
	else
		printf("%d\n",cntFIVE);
}
