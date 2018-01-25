#include<cstdio>
#include<iostream>

using namespace std;

int NumberStair[101][10];

int main(){
	int num;
	scanf("%d",&num);

	NumberStair[0][0] = 0;
	for(int i =1; i<10; i++)
		NumberStair[0][i] = 1;

	int index = 1;
	while(index < num+1){
		for(int j=0; j<10; j++){
			int down = 0;
			int up = 0;

			if(j-1 >= 0)
				down = NumberStair[index-1][j-1];
			if(j+1 < 10)
				up = NumberStair[index-1][j+1];
			
			NumberStair[index][j] = (down + up)% 1000000000;
		}
		index++;
	}

	/*for(int j=0 ; j<num; j++){
		for(int i = 0; i<10; i++)
		cout<<NumberStair[j][i]<<" ";
		cout<<endl;
	}*/
	

	int result = 0;
	for(int i = 0 ; i<10; i++)
		result = (result + NumberStair[num-1][i])%1000000000;
	printf("%d\n",result);
	
}

