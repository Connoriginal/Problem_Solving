#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int pic[65][65];

bool check(int x, int y, int len){
  for(int i = 0 ; i < len ; i++){
    for(int j = 0 ; j < len ; j++){
      if(pic[i + x][j + y] != pic[x][y]){
        return false;
      }
    }
  }
  return true;
}

void go(int x, int y, int len){
  if(check(x,y,len)){
    printf("%d",pic[x][y]);
    return;
  }

  printf("(");
  int l = len / 2;
  for(int i = 0 ; i < 2 ; i++){
    for(int j = 0 ; j < 2 ; j++){
      go(x + i*l, y + j*l, l);
    }
  }
  printf(")");
}

int main(void){
  int n;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      scanf("%1d",&pic[i][j]);
    }
  }

  go(0,0,n);
  printf("\n");
  return 0;
}
