#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;

char node[26][2];

void preorder(int x){
  if(x == -1) return;
  printf("%c",x + 'A');
  preorder(node[x][0]);
  preorder(node[x][1]);
}

void inorder(int x){
  if(x == -1) return;
  inorder(node[x][0]);
  printf("%c",x+'A');
  inorder(node[x][1]);
}

void postorder(int x){
  if(x == -1) return;
  postorder(node[x][0]);
  postorder(node[x][1]);
  printf("%c",x + 'A');
}

int main(void){
  int n;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++){
    char a,b,c;
    scanf(" %c %c %c",&a,&b,&c);
    b = (b == '.') ? -1 : b - 'A';
    c = (c == '.') ? -1 : c - 'A';
    node[a-'A'][0] = b;
    node[a-'A'][1] = c;
  }

  preorder(0);
  printf("\n");
  inorder(0);
  printf("\n");
  postorder(0);
  printf("\n");


  return 0;
}
