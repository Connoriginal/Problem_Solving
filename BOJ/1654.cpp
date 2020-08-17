#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


bool check(vector<int> &a, int x, int n){
  int ans = 0;
  for(int i = 0 ; i < a.size() ; i++){
    ans += a[i]/x;
  }
  return ans >= n;
}

int main(void){
  int k,n;
  scanf("%d %d",&k,&n);

  vector<int> a(k);

  long long l = 1, r = 0;
  long long ans = 0;

  for(int i = 0 ; i < k ; i++){
    scanf("%d",&a[i]);
    if(a[i] > r) r = a[i];
  }

  while(l <= r){
    long long mid = (l+r)/2;
    if(check(a,mid,n)){
      if(ans < mid) ans = mid;
      l = mid + 1;
    }
    else{
      r = mid - 1;
    }
  }

  printf("%lld\n",ans);
  return 0;
}
