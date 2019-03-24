#include<iostream>
#include<cstdio>

using namespace std;

char upper[3][3] = {{'a','b','c'},{'o','x','o'},{'o','o','x'}};

char cube[6][3][3] = {
                      {{'w','w','w'},{'w','w','w'},{'w','w','w'}},
                      {{'y','y','y'},{'y','y','y'},{'y','y','y'}},
                      {{'r','r','r'},{'r','r','r'},{'r','r','r'}},
                      {{'b','b','b'},{'b','b','b'},{'b','b','b'}},
                      {{'o','o','o'},{'o','o','o'},{'o','o','o'}},
                      {{'g','g','g'},{'g','g','g'},{'g','g','g'}}
                    };

// char cube[6][3][3] = {
//                       {{'o','w','w'},{'a','w','w'},{'o','a','o'}},
//                       {{'o','o','c'},{'o','y','y'},{'d','y','y'}},
//                       {{'b','b','c'},{'o','x','o'},{'o','o','x'}},
//                       {{'b','b','b'},{'o','b','b'},{'o','b','b'}},
//                       {{'o','o','o'},{'o','o','o'},{'o','o','d'}},
//                       {{'a','b','o'},{'o','x','o'},{'o','o','d'}}
//                     };

int rot[6][4] = {   {4,3,2,5},
                    {0,3,1,5},
                    {0,3,1,5},
                    {0,3,1,5},
                    {0,5,1,3},
                    {0,2,1,4}
                };

int changed[6][4][2] = {{{0,-1},{0,-1},{0,-1},{0,-1}},
                        {{2,-1},{-1,0},{0,-1},{-1,2}},
                        {{2,-1},{-1,0},{0,-1},{-1,2}},
                        {{2,-1},{-1,0},{0,-1},{-1,2}},
                        {{0,-1},{-1,0},{2,-1},{-1,2}},
                        {{-1,0},{-1,0},{-1,0},{-1,2}},
                    };

char * makecir(int rot[4],int change[4][2]){
  static char str[12];
  for(int r=0; r<4; r++){
    int x = change[r][0];
    int y = change[r][1];
    if(x == -1){
      if(r > 1){
        for(int i=3; i>0; i--)
          str[r*3+i] = cube[rot[r]][i][y];
      }else{
        for(int i=0; i<3; i++)
          str[r*3+i] = cube[rot[r]][i][y];
      }
    }else{
      for(int i=0; i<3; i++){
        str[r*3+i] = cube[rot[r]][x][i];
      }
      if(r > 1){
        for(int i=3; i>0; i--)
          str[r*3+i] = cube[rot[r]][x][i];
      }else{
        for(int i=0; i<3; i++)
          str[r*3+i] = cube[rot[r]][x][i];
      }
    }
  }
  return str;
}


void getarr(char *arr, int p, int x, int y){
  if(x==-1){
    for(int i=0; i<3; i++)
      arr[i] = cube[p][i][y];
  }else{
    for(int i=0; i<3; i++)
      arr[i] = cube[p][x][i];
  }
}

void setarr(char arr[3], int p, int x, int y, int inv){
  int i,j;
  if(x==-1){
    if(inv%2 == 0){
      for(i=0,j=2; i<3; i++,j--)
        cube[p][i][y] = arr[j];
    }else{
      for(i=0; i<3; i++)
        cube[p][i][y] = arr[i];
    }
  }else{
    if(inv%2 == 0){
      for(i=0,j=2; i<3; i++,j--)
        cube[p][x][i] = arr[j];
    }else{
      for(i=0; i<3; i++)
        cube[p][x][i] = arr[i];
    }
  }
}

void rotateB(int p, char d){
  if(d=='+'){
    char before[3];
    getarr(before, rot[p][0],changed[p][0][0],changed[p][0][1]);

    for(int r=0; r<4; r++){
      char temp[3];
      int n = (r+1)%4;
  //    cout<<n<<endl;
      getarr(temp,rot[p][n],changed[p][n][0],changed[p][n][1]);
  //    cout<<"b "<<before<<" t "<<temp<<endl;
      setarr(before,rot[p][n],changed[p][n][0],changed[p][n][1], n);
      for(int t=0; t<3; t++)
        before[t] = temp[t];
    }
  }else{
    char before[3];
    getarr(before, rot[p][3],changed[p][3][0],changed[p][3][1]);

    for(int r=3; r>=0; r--){
      char temp[3];
      int n = (r+3)%4;
  //    cout<<n<<endl;
      getarr(temp,rot[p][n],changed[p][n][0],changed[p][n][1]);
  //    cout<<"b "<<before<<" t "<<temp<<endl;
      setarr(before,rot[p][n],changed[p][n][0],changed[p][n][1], r);
      for(int t=0; t<3; t++)
        before[t] = temp[t];
    }
  }
    // cout<<cube[0][0][0]<<cube[0][1][0]<<cube[0][2][0]<<endl;
    // cout<<cube[2][0][0]<<cube[2][1][0]<<cube[2][2][0]<<endl;
    // cout<<cube[1][0][0]<<cube[1][1][0]<<cube[1][2][0]<<endl;
    // cout<<cube[4][0][2]<<cube[4][1][2]<<cube[4][2][2]<<endl;
}

void rotateP(int p, char d){
  char New[3][3];
  int i,j,x,y;

  if(d=='+'){
    for(i=2, x=0; i>=0; i--,x++){
      for(j=0,y=0; j<3; j++,y++)
        New[x][y] = cube[p][j][i];
    }
  }else{
    for(i=0, x=0; i<3; i++,x++){
      for(j=2,y=0; j>=0; j--,y++)
        New[x][y] = cube[p][j][i];
    }
  }

  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++)
      cube[p][i][j] =New[i][j];
  }

  // for(int i=0; i<3; i++){
  //   for(int j=0; j<3; j++)
  //     cout<<cube[p][i][j]<<" ";
  //     cout<<endl;
  // }
}

int main(){
  int testcase;
  scanf("%d",&testcase );
  while(testcase--){
    int L;
    scanf("%d",&L );
    for(int l=0; l<L; l++){
      char P[3];
      scanf("%s",P);

      int plane;
      switch(P[0]){
        case 'U':
          plane = 0;
          break;
        case 'F':
          plane =2;
          break;
        case 'B':
          plane = 4;
          break;
        case 'L':
          plane = 5;
          break;
        default:
          break;
      }
      rotateB(plane,P[1]);
      rotateP(plane,P[1]);


      for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
          printf("%c",cube[0][i][j] );
        printf("\n");
      }
    }

  }
}
