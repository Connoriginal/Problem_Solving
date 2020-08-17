#include <iostream>
#include <cstdio>

using namespace std;

const int mod = 1000000007;

int dp[101][10][2]; // 3rd : up or down

int main(void){
  int n;
  scanf("%d",&n);
  if(n == 1){
    printf("10\n");
    return 0;
  }

  for(int i = 0 ; i < 10 ; i++){
    for(int j = 0 ; j < 2 ; j++){
      dp[1][i][j] = 1;
    }
  }

  for(int i = 2 ; i <= n ; i++){
    for(int j = 0 ; j < 10 ; j++){
      if(j-1 >= 0){
        dp[i][j][0] = (dp[i][j][0] + dp[i-1][j-1][1]) % mod;
        if(j-2 >= 0) dp[i][j][0] = (dp[i][j][0] + dp[i-2][j-2][1]) % mod;
      }

      if(j+1 < 10){
        dp[i][j][1] = (dp[i][j][1] + dp[i-1][j+1][0]) % mod;
        if(j+2 < 10) dp[i][j][1] = (dp[i][j][1] + dp[i-2][j+2][0]) % mod;
      }
    }
  }

  int ans = 0;
  for(int i = 0 ; i < 10 ; i++){
    for(int j = 0 ; j < 2 ; j++){
      ans = (ans + dp[n][i][j]) % mod;
    }
  }

  printf("%d\n",ans);
  return 0;
}
