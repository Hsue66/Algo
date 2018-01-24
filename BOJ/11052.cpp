#include<cstdio>
#include<iostream>

using namespace std;

int Parr[1001]={0};
int Marr[1001]={0};

int main()
{
	int num;
	scanf("%d",&num);
	
	for(int i=1; i<num+1; i++){
		scanf("%d",&Parr[i]);
	}

	int loop = 1;
	while( loop < num+1){
		for(int i=0; i<loop; i++){
			int temp = Marr[i] + Parr[loop-i];
			if(temp > Marr[loop])
				Marr[loop] = temp;
			//cout<<temp<<" ";
		}
		//cout<<endl;
		loop++;
	}

	printf("%d\n",Marr[loop-1]);
}
