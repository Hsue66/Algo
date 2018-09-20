#include<cstdio>
//#include<iostream>
#include<map>
#include<cmath>

using namespace std;

int P;

long long calc(long long num){
  long long sum=0;
  while(num){
    sum = sum + pow(num%10,P);
    num = num / 10;
  }
  return sum;
}

int main(){
  map<long long, long long> Seq;
  int A;
  long long idx = 0;
  scanf("%d%d",&A,&P);
  Seq.insert(make_pair(A,idx++));

  int flag = 1;
  while(flag){
    long long val = calc(A);
    A = val;
    if(Seq.find(val)==Seq.end())
      Seq.insert(make_pair(val,idx++));
    else{
      flag = 0;
      printf("%lld\n",Seq.find(val)->second);
    }
  }
}
