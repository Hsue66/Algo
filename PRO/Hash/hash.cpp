#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

#define MAX_RECORD 500000
#define MAX_TABLE MAX_RECORD*2+7

void ztrcpy(char *dst, char *src){
  while(*dst++ = *src++);
}

int HashTB[MAX_TABLE];

void initHash(){
  for(int i=0; i<MAX_TABLE; i++)
    HashTB[i] = -1;
}

unsigned long getHash(const char* str){
  unsigned long hash = 5381;
  int c;
  while(c = *str++)
    hash = (((hash<<5)+hash)+c) % MAX_TABLE;
  return hash % MAX_TABLE;
}

int addToHashTB(char* str, int data){
  int hash = getHash(str);
  for(int i=0; i<MAX_TABLE; ++i){
    if(HashTB[hash] == -1){
      HashTB[hash] = data;
      return hash;
    }
    hash = (hash+1) % MAX_TABLE;
  }
  return -1;
}

int main(){
  char name[20] = "SUMI";
  int a = getHash(name);

  initHash();
  addToHashTB(name,1);
  cout<<HashTB[a]<<endl;
  ztrcpy(name, "hello");
  int h = getHash(name);
  addToHashTB(name,10);
  cout<<HashTB[h]<<endl;
}
