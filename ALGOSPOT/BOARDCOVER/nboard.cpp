#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int Board[21][21];
int H,W;
long long Cnt;
vector<pair<pair<int,int>,pair<int,int> > > patch;


void cover(){
	int x,y;
	int flag = 1;
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			if(Board[i][j] == 0){
				x = i;
				y = j;
				flag = 0;
				break;
			}		
		}
		if(flag==0)
			break;

	}

	if(flag)
		Cnt++;
	else{
		for(int t=0; t<4; t++){
			int tx1 = x+patch[t].first.first;
			int ty1 = y+patch[t].first.second;
			int tx2 = x+patch[t].second.first;
			int ty2 = y+patch[t].second.second;
			if((0<= tx1 && tx1 <H) && (0<= ty1 && ty1 <W) &&
				(0<= tx2 && tx2 <H) && (0<= ty2 && ty2 <W) &&
				(Board[tx1][ty1] == 0) && (Board[tx2][ty2] == 0)){
				Board[x][y] = Board[tx1][ty1] = Board[tx2][ty2] = 1;
				cover();
				Board[x][y] = Board[tx1][ty1] = Board[tx2][ty2] = 0;
			}
		}
	}
}


int main(){
	int testcase;
	scanf("%d",&testcase);
	patch.push_back(make_pair(make_pair(1,0),make_pair(1,1)));
	patch.push_back(make_pair(make_pair(0,1),make_pair(1,0)));
	patch.push_back(make_pair(make_pair(0,1),make_pair(1,1)));
	patch.push_back(make_pair(make_pair(1,0),make_pair(1,-1)));

	while(testcase--){
		scanf("%d%d",&H,&W);
		Cnt = 0;
		int temp =0;
		for(int i=0; i<H; i++){
			for(int j=0; j<W; j++){
				char ch;
				cin>>ch;
				if(ch == '#')
					Board[i][j] = 2;
				else{
					temp++;
					Board[i][j] = 0;
				}
			}
			cin.clear();
		}
		
		if(temp%3==0)
			cover();
		printf("%lld\n",Cnt);
	}
}
