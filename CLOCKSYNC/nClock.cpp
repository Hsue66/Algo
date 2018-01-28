#include <stdio.h>
#include <iostream>

using namespace std;
int MIN;			//	 0,1,2,3, 4,5,6,7  8,9,0,1  2,3,4,5
int Switch[10][16] = {	{3,3,3,0, 0,0,0,0, 0,0,0,0, 0,0,0,0},
						{0,0,0,3, 0,0,0,3, 0,3,0,3, 0,0,0,0},
						{0,0,0,0, 3,0,0,0, 0,0,3,0, 0,0,3,3},
						{3,0,0,0, 3,3,3,3, 0,0,0,0, 0,0,0,0},
						{0,0,0,0, 0,0,3,3, 3,0,3,0, 3,0,0,0},
						{3,0,3,0, 0,0,0,0, 0,0,0,0, 0,0,3,3},
						{0,0,0,3, 0,0,0,0, 0,0,0,0, 0,0,3,3},
						{0,0,0,0, 3,3,0,3, 0,0,0,0, 0,0,3,3},
						{0,3,3,3, 3,3,0,0, 0,0,0,0, 0,0,0,0},
						{0,0,0,3, 3,3,0,0, 0,3,0,0, 0,3,0,0} };

void clocksync(int* clock, int idx, int cnt){
	int check = 0;
	for(int i=0; i<16; i++){
		if(clock[i] != 0)
			check = 1;
	}	

	if(check == 0){
		if(MIN > cnt)
			MIN = cnt;
	}
	else{
		for(int j=0; idx <10 && j<4; j++){
			for(int t=0; t<16; t++){
				clock[t] = (clock[t]+Switch[idx][t]) % 12;
			}
			clocksync(clock,idx+1,cnt+(j+1)%4);
		}
	}
}

int main(){
	int testcase = 1;
	scanf("%d%*c",&testcase);
	for(; testcase>0; testcase--){
		MIN = 987654321;
		int Clock[16];	// = {12, 9, 3, 12, 6, 6, 9, 3, 12, 9, 12, 9, 12, 12, 6, 6};
		
		for(int i=0; i<16; i++){
			scanf("%d",&Clock[i]);
		}

		for(int i=0; i<16; i++){
			if(Clock[i] == 12)
				Clock[i] = 0;
		}

		clocksync(Clock, 0, 0);
		//clocksync(Clock,-1,0);

		if(MIN == 987654321)
			MIN = -1;

		printf("%d\n",MIN);

	}
}
