#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

long long cnt[1000];

int main(void){
  int n,m;
  scanf("%d %d",&n,&m);

  vector<int> sum(n+1);

  for(int i = 1 ; i <= n ; i++){
    int tmp;
    scanf("%d",&tmp);
    tmp %= m;
    sum[i] = (sum[i-1] + tmp) % m;
    cnt[sum[i]]++;
  }

  long long ans = cnt[0];

  for(int i = 0 ; i < m ; i++){
    ans += (cnt[i] * (cnt[i]-1)) / 2;
  }

  printf("%lld\n",ans);
  return 0;
}
