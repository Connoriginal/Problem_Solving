#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int n,m;
int a[10002];

int main(void){
  scanf("%d %d",&n,&m);
  for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
  sort(a,a+n);

  if(n == 1){
    printf("%d\n",abs(a[0]));
    return 0;
  }

  int l = 0, r = n-1, ans = 0;

  if(abs(a[0]) > a[n-1]){
    ans = abs(a[0]);
    l += m;
  }else {
    ans = abs(a[n-1]);
    r -= m;
  }

  for(; l < n && a[l] < 0; l += m){
    ans += abs(a[l]) * 2;
  }

  for(; r >= 0 && a[r] > 0 ; r -= m){
    ans += a[r] * 2;
  }

  printf("%d\n",ans);
  return 0;
}
