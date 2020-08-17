#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int a[100002];
int max_num[100002];
long long sum[100002];

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    memset(sum,0,sizeof(sum));
    memset(max_num,0,sizeof(max_num));
    int n,k,z;
    scanf("%d %d %d",&n,&k,&z);

    for(int i = 1 ; i <= n ; i++){
      scanf("%d",&a[i]);
      sum[i] = sum[i-1] + a[i];
      max_num[i] = max(max_num[i-1],a[i] + a[i-1]);
    }

    long long ans = sum[k+1];
    for(int i = 1 ; i <= z ; i++){
      long long fir = 0 ,sec = 0,tmp;;
      if(k+1 - 2*i > 0){
        fir = sum[k+1 - 2*i] + i * max_num[k+1 - 2*i];
      }
      if(k+1 - 2*(i-1) -2 > 0){
        sec = sum[k+1 - 2*(i-1) -1] + (i-1) * max_num[k+1 - 2*(i-1) -1] + a[k+1 - 2*i];

      }
      tmp = max(fir,sec);
      ans = max(ans,tmp);
    }
    printf("%lld\n",ans);
  }
  return 0;
}
