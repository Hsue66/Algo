#include<cstdio>
#include<iostream>

using namespace std;

int N,M,NM;

int main(){
	scanf("%d%d",&N,&M);
	NM = N-M;
	
	int cnt2=0, cnt5=0;
	int m2, m5, nm2, nm5;
	int cnt10;

	if(!M || !NM)
		cnt10 = 0;
	else{
		for(int i=1; i <= N; i++){
			int num = i;
			while(num%2 == 0 && num != 0){
				num = num/2;
				cnt2++;
			}
			while(num%5 == 0 && num != 0){
				num = num/5;
				cnt5++;
			}
			
			if(i == M){
				m2 = cnt2;
				m5 = cnt5;
			}
			if(i == NM){
				nm2 = cnt2;
				nm5 = cnt5;
			}
//			cout<<i<<" : "<<cnt2<<" "<<cnt5<<endl;
//			int a; cin>>a;
		}	
		int left2 = cnt2-m2-nm2;
		int left5 = cnt5-m5-nm5;
		cnt10 = min(left2,left5);
	}

	printf("%d\n",cnt10);
}


