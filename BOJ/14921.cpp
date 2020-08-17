#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int a[100001];

int main(void){
  int n;
  scanf("%d",&n);

  for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);

  if(n == 2) printf("%d\n",a[0] + a[1]);
  else{
    int lp = 0, rp = n-1;
    int ans = -200002;
    while(true){
      int sum = a[lp] + a[rp];
      ans = (abs(sum) < abs(ans)) ? sum : ans;
      if(sum < 0){
        lp++;
      }else if(sum > 0){
        rp--;
      }else{
        break;
      }

      if(lp == rp) break;
    }
    printf("%d\n",ans);
  }
  return 0;
}
