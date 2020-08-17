#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int d,n;
    scanf("%d %d",&d,&n);

    vector<long long> cnt(d);

    long long sum = 0;
    for(int i = 1 ; i <= n ; i++){
      long long tmp;
      scanf("%lld",&tmp);
      tmp %= d;
      sum = (sum + tmp) % d;
      cnt[sum]++;
    }

    long long ans = cnt[0];

    for(int i = 0 ; i < d ; i++){
      ans += cnt[i] * (cnt[i]-1) / 2;
    }

    printf("%lld\n",ans);
  }
  return 0;
}
