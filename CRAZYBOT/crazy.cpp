#include <iostream>
#include <vector>

using namespace std;

// g++ -std=c++11 your_file.cpp -o your_program
vector<vector<int>> arr(5, vector<int>(5,0));
int N;
double East;
double West;
double South;
double North;

void printvec(){
  for (vector<int> vec : arr) {
    for (int n : vec)
        printf("%d ", n);
    cout << endl;
  }
}

class CrazyBot{
public:
  double getProbability(int n, int east, int west, int south, int north){
    N = n;
    East = double(east)/100;
    West = double(west)/100;
    South = double(south)/100;
    North = double(north)/100;

    arr[arr.size()/2][arr.size()/2]= 1;
    printvec();
    cout<<"------------"<<endl;
    recur(n,arr.size()/2,arr.size()/2);
  }

  double recur(int n, int x, int y)
  {
    double result = 1;
    if(n>0){
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

        cout<<"["<<tx<<" , "<<ty<<"]  : " <<arr[tx][ty]<<endl;
        if(arr[tx][ty]!= 1){
          arr[tx][ty] = 1;
          result += multi*recur(n-1,tx,ty);
          cout<<"#### "<<result<<endl;
          arr[tx][ty]=0;
        }
        else{
          cout<<"------COLLAPSE-------"<<endl;
          result = 0;
        }

        if(N==n)
          cout<<"N result : "<<result<<endl;
      }
    }
    else if(n==0){
      result = 1;
    }


    return result;
  }

};



int main()
{
  CrazyBot crz;

  crz.getProbability(2,25,25,25,25);
  //cout<<crz.recur(2);
  /*
  for (vector<int> vec : arr) {
    for (int n : vec)
        printf("%d ", n);
    cout << endl;
  }
  */
}
