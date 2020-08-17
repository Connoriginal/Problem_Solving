#include <iostream>
#include <cstdio>


using namespace std;

int go(int x){
  if(x < 10){
    return x*10 + x;
  }
  else{
    int tmp = x/10 + x%10;
    return (x%10) * 10 + tmp%10;
  }
}

int main(void){
  int n;
  scanf("%d",&n);

  int ans = 1, next = go(n);

  while(next != n){
    next = go(next);
    ans++;
  }


  printf("%d\n",ans);
  return 0;
}
