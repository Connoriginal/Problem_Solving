#include <iostream>
#include <cstdio>

using namespace std;

bool dp[1001];

int main(void){
  int n;
  scanf("%d",&n);
  dp[1] = true; dp[2] = false; dp[3] = true;
  for(int i = 4 ; i <= n ; i++){
    if(!dp[i-1]) dp[i] = true;
    if(!dp[i-3]) dp[i] = true;
  }

  if(dp[n]) printf("SK\n");
  else printf("CY\n");
  return 0;
}
