#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool check[22];

long long fac(int x){
  long long ans = 1;
  for(int i = 1 ; i <= x ; i++){
    ans *= i;
  }
  return ans;
}

int main(void){
  int n;
  scanf("%d",&n);

  int prob;
  scanf("%d",&prob);

  if(prob == 1){
    long long k;
    scanf("%lld",&k);

    int len = n;

    for(int i = 1 ; i <= n ; i++){

      long long tmp = fac(n-i);
      int pt = 1;
      while(k - tmp > 0LL){
        k -= tmp;
        pt++;
      }

      int p = 0;
      for(int i = 1 ; i <= n ; i++){
        if(!check[i]){
          p++;
        }
        if(p == pt){
          check[i] = true;
          printf("%d ",i);
          break;
        }
      }

    }
    printf("\n");
  }

  else{
    long long ans = 1;
    int cnt = n;
    while(cnt--){
      long long tmp = fac(cnt);
      int k;
      scanf("%d",&k);
      check[k] = true;

      int p = 0;
      for(int i = 1 ; i < k ; i++){
        if(!check[i]) p++;
      }
      ans += p * tmp;
    }
    printf("%lld\n",ans);
  }

  return 0;
}
