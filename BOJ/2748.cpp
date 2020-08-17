#include <iostream>
#include <cstdio>

using namespace std;


long long fib[91];

int main(void){
  int n;
  scanf("%d",&n);

  fib[1] = 1; fib[2] = 1;
  for(int i = 3 ; i <= n ; i++){
    fib[i] = fib[i-1] + fib[i-2];
  }

  printf("%lld\n",fib[n]);
  return 0;
}
