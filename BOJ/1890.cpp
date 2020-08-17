#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a[102][102];
long long d[102][102];

int n;

int main(void){
  scanf("%d",&n);

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= n ; j++){
      scanf("%d",&a[i][j]);
    }
  }

  d[1][1] = 1;

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= n ; j++){
      int tmp = a[i][j];
      if(tmp == 0) break;
      if(i+tmp <= n) d[i+tmp][j] += d[i][j];
      if(j+tmp <= n) d[i][j+tmp] += d[i][j];
    }
  }

  printf("%lld\n",d[n][n]);
  return 0;
}
