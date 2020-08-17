#include <iostream>
#include <cstdio>

using namespace std;

bool dp[1001]; //false -> SK, true -> CY

int main(void){
  int n;
  scanf("%d",&n);
  dp[2] = true;
  for(int i = 5 ; i <= n ; i++){
    if(!(dp[i-1] || dp[i-3] || dp[i-4])) dp[i] = true;
  }
  if(dp[n]) printf("CY\n");
  else printf("SK\n");
  return 0;
}
