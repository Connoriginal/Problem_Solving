#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[100001];

int main(void){
  int n, m;
  scanf("%d %d",&n, &m);

  for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);

  sort(a, a+n);

  int l = 0 , r = 0;
  int ans = 2000000000;

  while(l < n && r < n){
    int temp = a[r] - a[l];
    if(temp >= m){
      ans = min(temp,ans);
      l++;
    }else{
      r++;
    }
  }

  printf("%d\n",ans);

  return 0;
}
