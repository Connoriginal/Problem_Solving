#include <iostream>
#include <cstdio>

using namespace std;

const int mod = 1000000000;

int d[201][201];

int main(void){
  int n,k;
  scanf("%d %d",&n,&k);

  d[0][0] = 1;

  for(int x = 0 ; x <= n ; x++){
    for(int y = 1 ; y <= k ; y++){
      for(int i = 0 ; i <= x ; i++){
        d[x][y] += d[x-i][y-1];
        d[x][y] %= mod;
      }
    }
  }

  printf("%d\n",d[n][k]);
  return 0;
}
