#include <iostream>
#include <cstdio>

using namespace std;

int t;

int main(void){
  scanf("%d",&t);
  while(t--){
    int n,m;
    scanf("%d %d",&n,&m);

    long long ans = 1;

    n = (n > m-n) ? m - n : n;

    for(int i = m ; i > m - n ; i--){
      ans *= i;
    }

    for(int i = 1 ; i <= n ; i++){
      ans /= i;
    }

    printf("%lld\n",ans);
  }
  return 0;
}
