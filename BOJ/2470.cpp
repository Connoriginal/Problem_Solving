#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int arr[100001];

int main(void){
  int n;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }

  sort(arr,arr+n);

  int ans_l = arr[0], ans_r = arr[n-1], ans = ans_l + ans_r;
  int lp = 0, rp = n-1, mid = 0;

  while(lp < rp){
    mid = arr[lp] + arr[rp];
    if(abs(ans) > abs(mid)){
      ans = mid; ans_l = arr[lp]; ans_r = arr[rp];
    }
    if(mid < 0) lp++;
    else rp--;
  }
  printf("%d %d\n",ans_l,ans_r);
  return 0;
}
