#include <iostream>
#include <cstdio>

using namespace std;

long long num2(long long n){
  long long ans = 0;
  for(long long i = 2 ; i <= n ; i *=2){
    ans += n/i;
  }
  return ans;
}

long long num5(int n){
  long long ans = 0;
  for(long long i = 5 ; i <= n ; i *= 5){
    ans += n/i;
  }
  return ans;
}

int main(void){
  long long n,m;
  scanf("%lld %lld",&n,&m);
  printf("%lld\n",min(num2(n)-num2(m)-num2(n-m),num5(n)-num5(m)-num5(n-m)));
  return 0;
}
