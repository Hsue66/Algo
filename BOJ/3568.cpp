#include<iostream>
#include<cstdio>
#include<string>
#include<stack>

using namespace std;

string command;
string type;
int main(){
  cin>>type;
  do{
    cin>>command;
    stack<string> S;
    string name = "";
    int flag = 0;
    S.push(";");
    for(unsigned i=0; i<command.size(); i++){
      if(isalpha(command[i]))
        name.append(command,i,1);
      else{
        if(flag == 0){
          flag = 1;
          S.push(name);
          S.push(" ");
        }
        if(flag == 1){
          if(command[i] == '['){
            S.push(command.substr(i,2));
            i = i+1;
          }
          else
            S.push(command.substr(i,1));
        }
      }
    }
    S.pop();
    S.push(type);
    while(!S.empty()){
      cout<<S.top();
      S.pop();
    }
    printf("\n");
  }while(command[command.size()-1] != ';');
}
