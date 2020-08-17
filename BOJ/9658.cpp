#include <iostream>
#include <cstdio>

using namespace std;

bool dp[1001]; // false : CY , true : SK

int main(void){
  int n;
  scanf("%d",&n);

  dp[2] = true;
  dp[4] = true;

  for(int i = 5 ; i <= n ; i++){
    if(!(dp[i-1] && dp[i-3] && dp[i-4])) dp[i] = true;
  }

  if(dp[n]) printf("SK\n");
  else printf("CY\n");
  return 0;
}
