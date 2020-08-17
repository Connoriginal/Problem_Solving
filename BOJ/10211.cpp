#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[1001], sum[1001];

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    memset(sum,0,sizeof(sum));
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++){
      scanf("%d",&a[i]);
      sum[i] = sum[i-1] + a[i];
    }

    int ans = -1001;
    for(int i = 1 ; i <= n ; i++){
      for(int j = i ; j <= n ; j++){
        ans = max(ans,sum[j] - sum[i-1]);
      }
    }

    printf("%d\n",ans);
  }
  return 0;
}
