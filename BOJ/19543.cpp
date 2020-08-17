#include <iostream>
#include <cstdio>

using namespace std;

int n,m,k;

char map[27][200002];

int main(void){
  scanf("%d %d %d",&n,&m,&k);
  for(int i = 0 ; i < k ; i++){
    scanf("%s",map[i]);
  }

  char str[200002];
  scanf("%s",str);

  long long ans = 0;
  int prev_l = m-2, prev_r = m-1;

  for(int i = n-1 ; i >= 0 ; i--){
    int cur = str[i] - 'A';

    if(i == n-1){
      while(prev_l >= 0 && map[cur][prev_l] != 'U') prev_l--;
      ans += prev_r - prev_l;
    }else{
      int l = prev_l;
      int r = prev_r;
      while(l >= 0 && map[cur][l] != 'U') l--;
      while(r > prev_l && map[cur][r] != 'U') r--;
      if(r < prev_l+1) break;
      ans += r - l;
      prev_r = r; prev_l = l;
    }
  }
  printf("%lld\n",ans);
  return 0;
}
