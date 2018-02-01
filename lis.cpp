#include <iostream>

using namespace std;

class DblList;
class DblNode{
  friend class DblList;
private:
  int data;
  DblNode *left, * right;

public:
  DblNode()
  {
    data=0;
    left = 0;
    right = 0;
  }
  DblNode

};

class DblList{
private:
  DblNode * head;
  DblNode *AV;

public:
  void Concat(DblList &b)
  {}
  void Insert(int data, DblNode *x)
  {}
  void Delete(DblNode *x)
  {}
};

int main(){
  DblNode a;
  DblNode b;
  a.getData(b);
}
