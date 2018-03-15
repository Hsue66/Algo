#include<cstdio>
#include<cmath>
//#include<iostream>

using namespace std;
int arr[1000001];

void searchNprime(int lower, int upper){
	int range = sqrt(upper) +1;
	for(int i=2; i<range; i++){
		if(arr[i] !=1){
			int start = lower/i;
			while(start*i<=upper){
				if(start != 1)
					arr[start*i] = 1;
				start++;
			}
		}
	}
/*	cout<<"hehehee"<<endl;
	for(int i=1; i<=upper; i++){
		if(arr[i]!= 1)
			cout<<i<<endl;
	}*/
}	

int main(){
	int before=0;
	int now;
	arr[0] = 1;
	arr[1] = 1;
	while(1){
		scanf("%d",&now);
		if(now == 0)
			break;
		else{
			if(now>before)
				searchNprime(before,now);
			int flag = 0;
			for(int i = 2; i<=now/2; i++){
				if(arr[i] != 1 && arr[now-i] != 1){
					flag = 1;
					printf("%d = %d + %d\n",now,i,now-i);
					break;
				}
			}
			if(flag!= 1)
				printf("Goldbach's conjecture is wrong.\n");
			before = now;
		}
	}
}
