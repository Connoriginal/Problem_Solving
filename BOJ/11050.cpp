#include <iostream>
#include <cstdio>

using namespace std;

int fac(int x){
  int ans = 1;
  while(x>0){
    ans *= x--;
  }
  return ans;
}
int main(void){
  int ans = 1;
  int n,k;
  scanf("%d %d",&n,&k);
  ans = fac(n)/fac(k)/fac(n-k);
  printf("%d\n",ans);
  return 0;
}
