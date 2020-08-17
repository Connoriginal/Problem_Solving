#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int go(int x, int y, int len){
  if(len == 2){
    return 2*x + y;
  }

  int l = len/2;

  if(x < l){
    if(y < l){
      return go(x,y,l);
    }
    else{
      return l*l + go(x,y-l,l);
    }
  }
  else{
    if(y < l){
      return l*len + go(x - l,y,l);
    }
    else{
      return l*l*3 + go(x- l,y-l,l);
    }
  }
  return 0;
}

int main(void){
  int n,r,c;
  scanf("%d %d %d",&n,&r,&c);

  printf("%d\n",go(r,c,1<<n));

  return 0;
}
