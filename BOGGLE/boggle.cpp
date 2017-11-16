#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<vector<char> > Board(5,vector<char>(5,0));
vector<vector<pair<int,int> > > Pos(26,vector<pair<int,int> >());
int flag;
char Sentence[10];
int check[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void boggle(int nowX, int nowY, int idx){
	for(int i=0; flag== 0 && i<8; i++){
		int moveX = nowX +check[i][0];
		int moveY = nowY +check[i][1];

		//cout<<moveX<<","<<moveY<<endl;
		if(0<=moveX && moveX<5 && 0<=moveY && moveY<5 && Sentence[idx] == Board[moveX][moveY]){
			if(idx == strlen(Sentence)-1)
				flag = 1;
			else
				boggle(moveX,moveY,idx+1);
		}
	}
}


int main(){
	int testcase;
	scanf("%d",&testcase);
	for(; testcase>0; testcase--){
		scanf("%*c");
		Pos.clear();
		for(int i=0; i<5; i++)
		{
			for(int j=0; j<5; j++){
				scanf("%c",&Board[i][j]);
				//Board[i][j] = Arr[k++];
				Pos[Board[i][j]-'A'].push_back(make_pair(i,j));
			}
			scanf("%*c");
		}
		
	/*	
		for(int i=0; i<26; i++)
		{
			for(int j=0; j<Pos[i].size(); j++)
				cout<<Pos[i][j].first<<","<<Pos[i][j].second<<" ";
			cout<<endl;
		}
		
		for(int i=0; i<5; i++)
		{
			for(int j=0; j<5; j++){
				cout<<Board[i][j]<<" ";
			}
			cout<<endl;
		}
	*/

		int test;
		scanf("%d",&test);
		for(; test>0; test--){
			scanf("%s",Sentence);
			flag = 0;

			for(int i=0; flag==0 && i<Pos[Sentence[0]-'A'].size(); i++){
				//cout<<"Start "<<Pos[Sentence[0]-'A'][i].first <<Pos[Sentence[0]-'A'][i].second<<endl;
				boggle(Pos[Sentence[0]-'A'][i].first,Pos[Sentence[0]-'A'][i].second,1);
			}

			if(flag == 1)
				printf("%s %s\n",Sentence,"YES");
			else	
				printf("%s %s\n",Sentence,"NO");
			
		}
	}
}
