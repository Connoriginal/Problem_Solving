#include <iostream>
#include <cstdio>

using namespace std;

const int mod = 10007;

int d[1001][10];

int main(void){
  int n;
  scanf("%d",&n);

  for(int i = 0 ; i < 10 ; i++){
    d[1][i] = 1;
  }

  for(int i = 2 ; i <= n ; i++){
    for(int j = 0 ; j < 10 ; j++){
      for(int k = 0 ; k <= j ; k++){
        d[i][j] = (d[i][j] + d[i-1][k])%mod;
      }
    }
  }

  int ans = 0;

  for(int i = 0 ; i < 10 ; i++){
    ans = (ans + d[n][i])%mod;
  }
  printf("%d\n",ans);
  return 0;
}
