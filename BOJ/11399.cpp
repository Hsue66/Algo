//#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int N;
int Time[1001];

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&Time[i]);

	sort(Time, Time+N);

	int sum=0;
	int before = 0;
	for(int i=0; i<N; i++){
		sum = before + Time[i] + sum;
		before += Time[i];
	}
	
	printf("%d\n",sum);
}
