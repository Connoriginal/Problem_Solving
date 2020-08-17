#include <iostream>
#include <cstdio>

using namespace std;

int dp[21][2]; // 0 그년도에 만들어진 개수, 1 총개수

int main(void){
  int n;
  scanf("%d",&n);
  dp[0][0] = 0;dp[0][1] = 0;
  dp[1][0] = 1;dp[1][1] = 1;
  dp[2][0] = 1;dp[2][1] = 2;
  dp[3][0] = 2;dp[3][1] = 4;
  for(int i = 4 ; i <= n; i++){
    dp[i][0] = dp[i-1][1];
    dp[i][1] = dp[i][0]*2;
    if(i%2==0){
      dp[i][1] -= dp[i-3][0] + dp[i-4][0];
    }
  }
  printf("%d\n", dp[n][1]);
  return 0;
}
