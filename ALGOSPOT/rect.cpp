#include <iostream>

using namespace std;

class Rectangle{
private:
  int x,y,w,h;

public:
  Rectangle(){};

  Rectangle(int x,int y, int w, int h )
  { this->x = x;
     this->y = y;
     this->w = w;
     this->h = h;
//    cout<<y<<endl;
  }

  operator==(Rectangle s)
  {
    if(this == &s)
      cout<<"HHHHHHHHHHHHHHHH";
    if(s.y==y){
      cout<<"he"<<endl;
      return 1;
    }
    else
      return 0;
  }
};

int main(){
  Rectangle r(1,2,3,4);
  Rectangle s(1,2,3,4);
  if(r==s)
    cout<<"a";
  else
      cout<<"b";
}
