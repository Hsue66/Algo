#include<cstdio>
#include<iostream>

using namespace std;

int N,L;
int M[101][101];
int S[101];

int Temp[101];
int cnt = 0;


void findPath(){
	int checked[101] ={0};
	int tIdx = 0;
	int flag;

	Temp[tIdx] = S[0];
	
	for(int i=1; i<N; i++){
		flag = 0;

		//cout<<Temp[tIdx] <<" -> "<<S[i]<<endl;
		//for(int t=0; t<N; t++)
		//	cout<<checked[t]<<" ";
		//cout<<endl;
		
		if(Temp[tIdx] == S[i])
			Temp[++tIdx] = S[i];

		else if(S[i]-Temp[tIdx] == 1){
			for(int k=0; k<L; k++){
				if(checked[tIdx-k] == 1 || tIdx-k < 0 || Temp[tIdx] != Temp[tIdx-k])
					flag = 1;
			}
			if(flag != 1){
				checked[tIdx] = 1;
				Temp[++tIdx] = S[i];
			}
		}

		else if(S[i]-Temp[tIdx] == -1){
			int k;
			for(k=0; k<L; k++){
				Temp[++tIdx] = S[i+k];
				checked[tIdx] = 1;
				if(i+k >= N || S[i] != S[i+k])
					flag = 1;
			}
			i = i+k-1;
		}

		else{
			flag = 1;
		//	cout<<"over 1 CANT"<<endl;
			break;
		}
		
		if(flag){
		//	cout<<"CANT"<<endl;
			break;
		}
	}

	if(flag==0)
		cnt++;
}

int main(){
	scanf("%d%d",&N,&L);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			scanf("%d",&M[i][j]);
	}

	for(int x=0; x<N; x++){
		for(int i=0; i<N; i++)
			S[i] = M[x][i];
		findPath();
	}

	for(int x=0; x<N; x++){
		for(int i=0; i<N; i++)
			S[i] = M[i][x];
		findPath();
	}
//	cout<<"------------------------------"<<endl;
	printf("%d\n",cnt);
}
