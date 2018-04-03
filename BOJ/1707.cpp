#include<cstdio>
#include<iostream>

using namespace std;

int Node;
int M[20001][20001] ={0};
int S[20001];
int top;
int Cnt[20001] = {0};
int checked[20001] = {0};
int Odd;

void accu(int num){
	int cnt=0;
	for(int i=top; i>0; i--){
		cnt += 1;
		if(S[i] == num){
			Cnt[num] = cnt;
			if(Cnt[num]%2 == 1)
				Odd = 1;
			break;
		}
	}
}

void search(){
	int now = S[top];
	
	int flag = 1;
	for(int i=0; i<Node; i++){	
		if(M[now][i]){
			if(checked[i] && S[top-1] != i)
				accu(i);
			
			else if(checked[i] == 0){
				S[++top] = i;
				checked[i] = 1;
				flag = 0;
				break;
			}
		}
	}
/*	
 	cout<<now<<endl;	
 	for(int i=0; i<Node; i++)
		cout<<Cnt[i]<<" ";
	cout<<endl;
*/
	if(flag)
		top--;

	if(top > 0)
		search();
}

int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		int m;
		scanf("%d%d",&Node,&m);
	
		//init	
		for(int i=0; i<Node; i++)
			fill_n(M[i],Node,0);
		fill_n(checked,Node,0);
		fill_n(Cnt,Node,0);
		Odd = 0;
		top = 0;

		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			M[x-1][y-1] = 1;
			M[y-1][x-1] = 1;
		}
				
		checked[0] = 1;
		S[++top] = 0;
		search();

		if(Odd)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
