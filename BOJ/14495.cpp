#include <iostream>
#include <cstdio>

using namespace std;

long long fib[120];
int n;

int main(void){
  scanf("%d",&n);
  fib[1] = fib[2] = fib[3] = 1; fib[4] = 2;

  for(int i = 4 ; i <= n ; i++){
    fib[i] = fib[i-1] + fib[i-3];
  }

  printf("%lld\n",fib[n]);
  return 0;
}
