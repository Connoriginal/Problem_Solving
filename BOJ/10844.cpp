#include <iostream>
#include <cstdio>

using namespace std;

const int mod = 1000000000;

int d[101][10];

int main(void){
  for(int i = 1 ; i <= 9 ; i++){
    d[1][i] = 1;
  }

  int n;
  scanf("%d",&n);
  for(int i = 2; i <= n ; i++){
    for(int j = 1 ; j < 9 ; j++){
      d[i][j] = (d[i-1][j-1] + d[i-1][j+1])%mod;
    }
    d[i][0] = d[i-1][1]%mod;
    d[i][9] = d[i-1][8]%mod;
  }

  int ans = 0;
  for(int i = 0 ; i < 10 ; i++){
    ans = (ans + d[n][i])%mod;
  }

  printf("%d\n",ans);
  return 0;
}
