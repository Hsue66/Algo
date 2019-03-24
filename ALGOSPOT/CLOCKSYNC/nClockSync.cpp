#include<cstdio>
#include<vector>
//#include<iostream>
#define UPPER 987654321
using namespace std;

vector<int> S[10] ={{0,1,2},{3,7,9,11},{4, 10, 14, 15},{0, 4, 5, 6, 7},{6, 7, 8, 10, 12},
					{0, 2, 14, 15},{3, 14, 15},{4, 5, 7, 14, 15},{1, 2, 3, 4, 5},{3, 4, 5, 9, 13}};
int MIN;

void pushSwitch(int* CLOCK, int btn, int cnt){
	int flag = 1;
	for(int i=0; i<16; i++){
		if(CLOCK[i] != 0){
			flag = 0;
			break;
		}
	}

	if(flag){
		if(MIN > cnt)
			MIN = cnt;
	}
	else{
		for(int i=0; btn<10 && i<4; i++){
			for(int j=0; j<S[btn].size(); j++)
				CLOCK[S[btn][j]] = (CLOCK[S[btn][j]] + 3) %12;

			pushSwitch(CLOCK,btn+1, cnt+(i+1)%4);		
		}
	}
}

int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		int CLOCK[16];
		for(int i=0; i<16; i++){
			scanf("%d",&CLOCK[i]);
			CLOCK[i] = CLOCK[i]%12;
		}
		MIN = UPPER;	
	
		pushSwitch(CLOCK,0,0);
		
		if(MIN==UPPER)
			MIN = -1;
		printf("%d\n",MIN);
	}
}
