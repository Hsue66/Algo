#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

queue<pair<int,int> > NumQ;

int checkNpush(int num, int cnt){
	if(num == 1){
		printf("%d\n",cnt);
		return -1;
	}
	else{
		NumQ.push(pair<int,int>(num,cnt));
		return 0;
	}
}


int main(){
	int num;
	int cnt = 0;
	scanf("%d",&num);
	checkNpush(num,cnt);

	while(!NumQ.empty()){
		num = NumQ.front().first;
		cnt = NumQ.front().second +1;
		NumQ.pop();
		if(num%3 == 0){
			if( -1 == checkNpush(num/3,cnt))
				break;
		}
		if(num%2 == 0){
			if( -1 == checkNpush(num/2, cnt))
				break;
		}
		if(num-1 > 0){
			if( -1 == checkNpush(num-1, cnt))
				break;
		}
	}

}
