#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(void){
  int n,k;
  scanf("%d %d",&n,&k);

  vector<int> vec(n);

  for(int i = 0 ; i < n ; i++) scanf("%d",&vec[i]);

  int s = 0, e = 0;
  int cnt = (vec[e] == 1) ? 1 : 0;
  int ans = n+1;

  while(s < n){
    if(cnt < k){
      if(e == n-1){
        s++;
        continue;
      }
      e++;
      if(vec[e] == 1) cnt++;
    }else{
      if(vec[s] == 1) cnt--;
      s++;
    }
    if(cnt == k) ans = min(ans,e-s+1);
  }

  if(ans == n+1) printf("-1\n");
  else printf("%d\n",ans);

  return 0;
}
