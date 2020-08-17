#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool check(vector<int> &a, int l, int m){
  long long ans = 0;
  for(int i = 0 ; i < a.size() ; i++){
    ans += (a[i] - l >= 0) ? a[i] - l : 0;
  }
  return ans >= m;
}

int main(void){
  int n,m;
  scanf("%d %d",&n,&m);

  vector<int> a(n);
  long long low = 1, high = 0;
  long long ans = 0;

  for(int i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
    if(a[i] > high) high = a[i];
  }

  while(low <= high){
    long long mid = (low + high)/2;
    if(check(a,mid,m)){
      if(ans < mid) ans = mid;
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }

  printf("%lld\n",ans);
  return 0;
}
