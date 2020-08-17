#include <iostream>
#include <cstdio>

using namespace std;

int static mod = 1000000007;

int dp[1003][1003];


int main(void){
  int n,m;
  scanf("%d %d",&n,&m);
  dp[1][1] = 1;

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % mod;
      dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
      dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % mod;
    }
  }
  printf("%d\n",dp[n][m]);
  return 0;
}
