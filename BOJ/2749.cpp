#include <iostream>
#include <cstdio>

using namespace std;

long long fib[1500000];
int main(void){
  long long n;
  scanf("%lld",&n);

  n = n % (1500000);

  fib[0] = 0;fib[1] = 1;
  for(int i = 2 ; i <= n ; i++){
    fib[i] = fib[i-1] + fib[i-2];
    fib[i] %= 1000000;
  }

  printf("%lld\n",fib[n]);
  return 0;
}
