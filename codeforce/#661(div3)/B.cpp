#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);
    vector<int> a(n),b(n);

    int a_min = 1e9 + 1, b_min = 1e9+1;
    for(int i = 0 ; i < n ; i++){
      scanf("%d",&a[i]);
      a_min = min(a[i],a_min);
    }
    for(int i = 0 ; i < n ; i++){
      scanf("%d",&b[i]);
      b_min = min(b[i],b_min);
    }

    long long ans = 0;
    for(int i = 0 ; i < n ; i++){
      int u,v;
      u = a[i] - a_min;
      v = b[i] - b_min;
      ans += max(u,v);
    }

    printf("%lld\n",ans);
  }
  return 0;
}
