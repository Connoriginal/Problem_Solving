#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int check[1000000];
int a,p;
int cnt = 0;

int pow(int x, int y){
  int ans = 1;
  for(int i = 0 ; i < y ; i++){
    ans *= x;
  }
  return ans;
}

int go(int x){
  cnt +=1 ;
  check[x] = cnt;

  int y = 0;
  while(x > 0){
    y += pow(x%10,p);
    x /= 10;
  }

  if(check[y] == 0)
    return go(y);
  else
    return check[y]-1;
}

int main(void){
  scanf("%d %d",&a,&p);

  int st = go(a);

  printf("%d\n",st);
  return 0;
}
