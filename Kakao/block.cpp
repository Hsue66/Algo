#include<iostream>
#include <string>
#include <vector>

#include <stack>
#define LIMIT 31
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    int erase = 1;
    while(erase){
      stack<pair<int,int> > st;

      for(int i=0; i<m-1; i++){
        for(int j=0; j<n-1; j++){
          char now = board[i][j];
          if(now != '0' && now == board[i][j+1] && now == board[i+1][j] && now == board[i+1][j+1])
            st.push(make_pair(i,j));
        }
      }

      if(st.size() == 0)
        erase = 0;

      while(!st.empty()){
        int x = st.top().first;
        int y = st.top().second;
        board[x][y]='0';
        board[x][y+1]='0';
        board[x+1][y]='0';
        board[x+1][y+1]='0';
        st.pop();
      }

      for(int j=0; j<n; j++){
        for(int i=n-1; i>0; i--){
          if(board[i][j] =='0'){
            int idx = i;
            while(idx--){
              if(board[idx][j] != '0'){
                board[i][j] = board[idx][j];
                board[idx][j] ='0';
                break;
              }
            }
          }
        }
      }

    /*
      for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
          cout<<board[i][j]<<" ";
          cout<<endl;
        }
      cout<<endl;
      */
    }

    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++)
        if(board[i][j] =='0')
          answer++;
      }

    return answer;
}

int main(){
  vector<string> board;
//  /*
  board.push_back("TTTANT");
  board.push_back("RRFACC");
  board.push_back("RRRFCC");
  board.push_back("TRRRAA");
  board.push_back("TTMMMF");
  board.push_back("TMMTTJ");
/*
 	board.push_back("CCBDE");
  board.push_back("AAADE");
  board.push_back("AAABF");
  board.push_back("CCBBF");
  */
  cout<<solution(6,6,board)<<endl;
}
