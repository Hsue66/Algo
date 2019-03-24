#include <stdio.h>
#include <iostream>

using namespace std;

int stdNum;
int Friend[10][10];
int Count;

void picnic(int *check){
	int finish = 1;
	for(int sIdx = 0; sIdx <stdNum; sIdx++){
		if(check[sIdx] == 0)
			finish = 0;
	}

	if(finish == 1){
		Count++;
	//	cout<<"PAIR!! "<<Count<<endl;
	}
	else{
		for(int i =0; i<stdNum; i++){
			if(check[i] != 1){
				check[i] = 1;
				for(int j =0; j<stdNum; j++){
					if(Friend[i][j] == 1 && check[j] == 0){
						check[j] = 1;
						picnic(check);
						check[j] = 0;
					}
				}
				check[i] = 0;
				break;
			}
		}
	}
}

int main(){
	int testcase;
	scanf("%d%*c",&testcase);
	//testcase = 1;
	for(; testcase > 0; testcase--){
		Count = 0;
		for(int i=0; i<10; i++)
			fill_n(Friend[i],10,0);

		int friNum;	
		scanf("%d%d",&stdNum,&friNum);
		
		
		for(; friNum > 0; friNum--){
			int tempX,tempY;
			scanf("%d%d",&tempX,&tempY);
			Friend[tempX][tempY] = 1;
			Friend[tempY][tempX] = 1;
		}

		int check[10] = {0};
		for(int sIdx=0; sIdx <stdNum; sIdx++){
			check[0] = 1;
			if(Friend[0][sIdx] == 1){
				check[sIdx] = 1;
				picnic(check);
				check[sIdx] = 0;
			}
		}
		printf("%d\n",Count);
/*
		cout<<"Friend"<<endl;
		for(int i=0; i<stdNum; i++)
		{
			for(int j=0; j<stdNum; j++)
				cout<<Friend[i][j]<<" ";
			cout<<endl;
		}
*/
	}
}
