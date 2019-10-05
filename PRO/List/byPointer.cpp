#include<stdio.h>

#define MAX 10000

struct Node{
  Node *prev;
  Node *next;
  int val;
};

struct List{
  Node *HEAD;
  Node *TAIL;
  int idx;
  Node node[MAX];

  void init(){
    idx = 0;
    HEAD = alloc();
    TAIL = alloc();

    HEAD->next = TAIL;
    TAIL->prev = HEAD;
  }

  void push_back(int data){
    Node *tmp = alloc();
    tmp->val = data;
    Node *prev = TAIL->prev;
    Node *next = prev->next;

    tmp->prev = prev;
    tmp->next = next;
    prev->next = tmp;
    next->prev = tmp;
  }

  void pop_back(){
    Node *prev = TAIL->prev->prev;
    Node *next = TAIL;

    prev->next = TAIL;
    TAIL->prev = prev;
  }

  void push_front(int data){
    Node *tmp = alloc();
    tmp->val = data;
    Node *next = HEAD->next;
    Node *prev = next->prev;

    tmp->prev = prev;
    tmp->next = next;
    prev->next = tmp;
    next->prev = tmp;
  }

  void pop_front(){
    Node *prev = HEAD;
    Node *next = HEAD->next->next;

    prev->next = next;
    next->prev = prev;
  }

  void insert(int p, int data){
    Node *it = HEAD->next;
    int i=0;
    for(; it!= TAIL && i++ != p; it=it->next);

    Node *tmp = alloc();
    tmp->val = data;

    it->prev->next = tmp;
    tmp->prev = it->prev;
    tmp->next = it;
    it->prev = tmp;
  }

  void erase(int p){
    Node *it = HEAD->next;
    int i=0;
    for(; it!= TAIL && i++ != p; it=it->next);

    it->prev->next = it->next;
    it->next->prev = it->prev;
  }

  Node* alloc(){
    return &node[idx++];
  }

  void show(){
    Node *Next = HEAD->next;
    for(Node *it = HEAD->next ; it != TAIL ; it = it->next){
      printf("%d -> ", it->val);
    }
    printf("\n");
  }
};





int main(){
  List list;
  list.init();

  list.push_back(3);
  list.push_back(5);
  list.push_back(2);
  list.show();

  list.pop_front();
  list.show();

  list.push_front(1);
  list.push_front(6);
  list.show();
  list.pop_back();
  list.show();

  list.insert(1,7);
  list.show();

  list.erase(2);
  list.show();
}
