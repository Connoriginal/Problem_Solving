#include <iostream>
#include <cstdio>

using namespace std;

int fib[21];
int n;

int main(void){
  scanf("%d",&n);
  fib[0] = 0; fib[1] = fib[2] = 1;

  for(int i = 3 ; i <= n ; i++){
    fib[i] = fib[i-1] + fib[i-2];
  }

  printf("%d\n",fib[n]);
  return 0;
}
