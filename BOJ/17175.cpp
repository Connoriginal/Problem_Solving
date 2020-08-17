#include <iostream>
#include <cstdio>

using namespace std;

int static d = 1000000007;

int dp[51];

int fibonacci(int n){
  if(dp[n] > 0) return dp[n];
  if(n < 2) return 1;
  return dp[n] = (1 + fibonacci(n-1) + fibonacci(n-2))%d;
}

int main(void){
  int n;
  scanf("%d",&n);
  printf("%d\n",fibonacci(n));
  return 0;
}
