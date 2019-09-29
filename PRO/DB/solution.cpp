
typedef enum
{
   NAME,
   NUMBER,
   BIRTHDAY,
   EMAIL,
   MEMO
} FIELD;

typedef struct
{
   int count;
   char str[20];
} RESULT;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

#define MAX_LEN 20
#define MAX_RECORD 50000
#define MAX_TABLE MAX_RECORD*2+7

void ztrcpy(char *dst, char *src){
  while(*dst++ = *src++);
}

int ztrcmp(char *dst, char *src){
  int i=0,j=0;
  while(dst[i]){
    if(dst[i++] != src[j++])
      break;
  }
  return dst[i]-src[j];
}

struct Record{
  int active;
  char fields[5][MAX_LEN];
  int hashkey[5];
};

Record DB[MAX_RECORD];
int DBidx;
int HashTB[5][MAX_TABLE];

unsigned long getHash(char *str){
  unsigned long hash = 5381;
  int c;
  while(c = *str++)
    hash = (((hash>>5)+hash)+c) % MAX_TABLE;
  return hash % MAX_TABLE;
}

int addToHashTB(char *str, int data, int fields){   // HashTBㅇㅔ 넣기
  int hash = getHash(str);
  for(int i=0; i<MAX_TABLE; i++){
    if(HashTB[fields][hash] == -1){
      HashTB[fields][hash] = data;
      return hash;
    }
    hash = (hash+1) % MAX_TABLE;
  }
  return -1;
}

void InitDB()
{
  DBidx = 0;
  for(int i=0; i<5; i++){
    for(int j=0; j<MAX_TABLE; j++)
      HashTB[i][j] = -1;
  }
}

void Add(char* name, char* number, char* birthday, char* email, char* memo)
{
  DB[DBidx].active = 1;
  ztrcpy(DB[DBidx].fields[0], name);
  ztrcpy(DB[DBidx].fields[1], number);
  ztrcpy(DB[DBidx].fields[2], birthday);
  ztrcpy(DB[DBidx].fields[3], email);
  ztrcpy(DB[DBidx].fields[4], memo);

  for(int i=0; i<5; i++)
    DB[DBidx].hashkey[i] = addToHashTB(DB[DBidx].fields[i], DBidx, i);

  DBidx++;
}

int Delete(FIELD field, char* str)
{
   return -1;
}

int Change(FIELD field, char* str, FIELD changefield, char* changestr)
{
   return -1;
}

RESULT Search(FIELD field, char* str, FIELD ret_field)
{
   RESULT result;
   result.count = 0;

   int hash = getHash(str);
   for(int i=0; i<MAX_TABLE; i++){
     if(HashTB[field][hash] == -1) break;
     int idx = HashTB[field][hash];
     if(DB[idx].active == 1 && !ztrcmp(str,DB[idx].fields[field])){
       ztrcpy(result.str, DB[idx].fields[ret_field]);
       result.count++;
     }
     hash = (hash+1) % MAX_TABLE;
   }
   return result;
}

char A[5][5][20]= {{"A","111","0101","a.com","aaa"},
{"B","222","0202","b.com","bbb"},
{"C","333","0303","c.com","ccc"},
{"D","444","0404","d.com","ddd"},
{"E","555","0505","e.com","eee"}};

void Test(){
  cout<<"hello"<<endl;
  InitDB();
  for(int i=0; i<5; i++)
    Add(A[i][0],A[i][1],A[i][2],A[i][3],A[i][4]);

  RESULT res = Search(NAME,A[0][0],EMAIL);
  cout<<res.count<<" "<<res.str<<endl;

}
