#include <iostream>
#include <cstdio>

using namespace std;

long long dp[65][10];
// fst : 자리수 , sec : 제일 왼쪽의 수

int main(void){

  for(int i = 0 ; i < 10 ; i++) dp[1][i] = 1;

  for(int i = 2 ; i < 65 ; i++){
    for(int j = 0 ; j < 10 ; j++){
      for(int k = j ; k < 10 ; k++){
        dp[i][j] += dp[i-1][k];
      }
    }
  }

  int T;
  scanf("%d",&T);

  for(int test_case = 1 ; test_case <= T ; test_case++){
    int n;
    scanf("%d",&n);

    long long ans = 0;
    for(int i = 0 ; i < 10 ; i++) ans += dp[n][i];

    printf("%lld\n",ans);
  }
  return 0;
}
