#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n,m;
int a[10001];

int main(void){
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
  scanf("%d",&m);

  sort(a,a+n);

  int l = 0, r = a[n-1];

  int ans = 0, mid;
  while(l <= r){
    mid = (l+r)/2;
    long long sum = 0;
    for(int i = 0 ; i < n ; i++){
      sum += min(a[i],mid);
    }
    if(sum <= m){
      ans = mid;
      l = mid +1;
    }else{
      r = mid - 1;
    }
  }
  printf("%d\n",ans);
  return 0;
}
