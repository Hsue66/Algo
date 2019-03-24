#include <iostream>
#include <vector>

using namespace std;

// g++ -std=c++11 your_file.cpp -o your_program
vector<vector<int>> arr(29, vector<int>(29,0));
int N;
double East;
double West;
double South;
double North;


class CrazyBot{
public:
  double getProbability(int n, int east, int west, int south, int north){
    N = n;
    East = double(east)/100;
    West = double(west)/100;
    South = double(south)/100;
    North = double(north)/100;

    //arr[arr.size()/2][arr.size()/2]= 1;
    return recur(n,arr.size()/2,arr.size()/2);
  }

  double recur(int n, int x, int y)
  {
    if(arr[x][y]==1)
      return 0;
    if(n==0)
      return 1;

    arr[x][y] = 1;
    double result=0;
    for(int i=0; i<4; i++){
      int tx = x;
      int ty = y;
      double multi = 1;
      if(i==0){
        multi = East;
        ty = y+1;
      }
      else if(i==1){
        multi = West;
        ty = y-1;
      }
      else if(i==2){
        multi = South;
        tx = x-1;
      }
      else if(i==3){
        multi = North;
        tx = x+1;
      }

      result += multi*recur(n-1,tx,ty);
    }
    arr[x][y]=0;
    return result;
  }

};



int main()
{
  CrazyBot crz;

  //cout<<crz.getProbability(1,25,25,25,25);
  cout<<crz.getProbability(14,25,25,25,25);//crz.getProbability(14,50,50,0,0);//crz.getProbability(7,50,0,0,50);
}
