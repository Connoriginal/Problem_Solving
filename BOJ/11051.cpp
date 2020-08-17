#include <iostream>
#include <cstdio>

using namespace std;
const int mod = 10007;

int d[1001][1001];

int main(void){
  int n,k;
  scanf("%d %d",&n,&k);

  d[1][0] = 1; d[1][1] = 1;

  for(int i = 2; i <= n ; i++){
    for(int j = 0 ; j <= i ; j ++){
      if(j == 0 || j == i){
        d[i][j] = 1;
      }
      else{
        d[i][j] = (d[i-1][j-1] + d[i-1][j])%mod;
      }
    }
  }

  printf("%d\n",d[n][k]);
  return 0;
}
