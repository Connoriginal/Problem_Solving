#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int check(int x){
  int tmp = x;
  while(x>0){
    tmp += x%10;
    x /= 10;
  }
  return tmp;
}

int main(void){
  int n;
  scanf("%d",&n);

  for(int i = 1 ; i <= n ; i++){
    if(check(i) == n){
      printf("%d\n",i);
      return 0;
    }
  }

  printf("0\n");
  return 0;
}
