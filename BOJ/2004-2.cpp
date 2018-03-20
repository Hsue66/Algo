#include<cstdio>
//#include<iostream>

using namespace std;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	
	int cntTWO = 0;
	int cntFIVE = 0;
	if(m==0 || n==m)
		printf("0\n");
	else{
		int now = n;
		while(now >n-m){
			int temp = now;
			while(temp%5 == 0){
				cntFIVE++;
				temp = temp/5;
			}
			while(temp%2 == 0){
				cntTWO++;
				temp = temp/2;
			}
			now--;
		}
		while(m--){
			int temp = m+1;
			while(temp%5 == 0){
				cntFIVE--;
				temp = temp/5;
			}
			while(temp%2 == 0){
				cntTWO--;
				temp = temp/2;
			}
		}
		//cout<<cntTWO<<" "<<cntFIVE<<endl;
		if(cntTWO < cntFIVE)
			printf("%d\n",cntTWO);
		else
			printf("%d\n",cntFIVE);
	}
}
