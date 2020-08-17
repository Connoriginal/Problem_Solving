#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const long long mod = 1000000007;

map<long long,long long> d;

long long go(long long x){
  if(x == 0) return 0;
  if(x == 1) return 1;
  if(d.count(x) > 0){
    return d[x];
  }
  if(x % 2 == 0){
    long long tmp,tmp2;
    tmp = go(x/2);
    tmp2 = go(x/2 -1);
    d[x] = ((2*tmp2 + tmp) * tmp) % mod;
    return d[x];
  }

  else{
    long long tmp,tmp2;
    tmp = go(x/2);
    tmp2 = go(x/2 +1);
    d[x] = (tmp*tmp + tmp2 * tmp2)%mod;
    return d[x];
  }
}

int main(void){
  long long n;
  scanf("%lld",&n);
  printf("%lld\n",go(n));
  return 0;
}
