#include <iostream>
#include <cstdio>

using namespace std;


int main(void){
  int n;
  scanf("%d",&n);

  int ans = 0;

  int digit_num = 1;
  int now = 10;

  while(n >= now){
    ans += digit_num * (now - now/10);
    now *= 10;
    digit_num++;
  }

  ans += (n - now/10 + 1)*digit_num;

  printf("%d\n",ans);
  return 0;
}
