#include <iostream>
#include <cstdio>

using namespace std;

int n,m;
int arr[100001][11], dp[100001][11];

int main(void){
  scanf("%d %d",&n,&m);

  for(int i = 0 ; i < m ; i++){
    for(int j = 0 ; j < n ; j++){
      scanf("%d",&arr[j][i]);
      if(j == 0) dp[0][i] = arr[0][i];
    }
  }

  for(int i = 1 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      for(int k = 0 ; k < m ; k++){
        int cur = arr[i][k];
        if(j == k) cur /= 2;
        dp[i][k] = max(dp[i][k],dp[i-1][j] + cur);
      }
    }
  }

  int ans = 0;
  for(int i = 0 ; i < m ; i++) ans = max(ans,dp[n-1][i]);
  printf("%d\n",ans);
  return 0;
}
