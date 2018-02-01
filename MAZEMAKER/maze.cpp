#include <iostream>
#include <vector>

using namespace std;

class MazeMaker{

public:
  int longestPath(vector<string> maze, int startRow, int startCol,
                  vector<int> moveRow, vector<int> moveCol )
  {
    int longest = -1;
      cout<<startRow.size();
    return longest;
  }

}

int main(){
  /*
  vector<vector<int>> arr(3, vector<int>(3,0));

  arr[0][1]=1;
  for (vector<int> vec : arr) {
    for (int n : vec)
        printf("%d ", n);
    cout << endl;
  }
*/
  vector<string> maze(50);
  maze = {"...","...","..."};
  cout<<maze.size();

  vector<int> moveRow(50);
  vector<int> moveCol(50);
  moveRow = {1,0,-1,0};
  moveCol = {0,1,0,-1};

  MazeMaker maker;
  maker.longestPath(maze,0,2,moveRow,moveRow, moveCol);

}
