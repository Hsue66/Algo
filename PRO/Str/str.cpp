#include<stdio.h>

void ztrcpy(char *dst, char *src){
  while(*dst++ = *src++);
}

int ztrcmp(char *str1, char *str2){
  int i=0;
  while(str1[i] != '\0' && str1[i] == str2[i])
    i++;
  return str1[i]-str2[i];
}

int ztrlen(char *str){
  int i=0;
  while(*str++) i++;
  return i;
}

int main(){
  char a[10] = "hello now";
  char b[10] = "hello naw";
  char c[10];
  char d[10];

  printf("COPY\n");
  printf("%s\n",c );
  ztrcpy(c,a);
  printf("%s\n",c );

  printf("COMPARE\n");
  printf("%d\n",ztrcmp(a,b));
  printf("%d\n",ztrcmp(a,c));
  printf("%d\n",ztrcmp(c,d));

  printf("LENGTH\n");
  printf("%d\n",ztrlen(a));
  printf("%d\n",ztrlen(d));
}
