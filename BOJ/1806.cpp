#include <iostream>
#include <cstdio>

using namespace std;

int a[100001];

int main(void){
  int n,s;
  scanf("%d %d",&n,&s);

  for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);

  int l = 0, r = 0;
  int sum = a[0], ans = 100001;
  while(l < n){
    if(sum < s){
      if(r == n-1){
        l++;
        continue;
      }
      sum += a[++r];
    }else{
      ans = min(ans,r-l+1);
      sum -= a[l++];
    }
  }

  if(ans == 100001) ans = 0;

  printf("%d\n",ans);
  return 0;
}
