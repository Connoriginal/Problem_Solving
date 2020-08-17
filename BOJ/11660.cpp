#include <iostream>
#include <cstdio>

using namespace std;

int a[1025][1025], sum[1025][1025];

int main(void){
  int n,m;
  scanf("%d %d",&n,&m);

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= n ; j++){
      scanf("%d",&a[i][j]);
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
    }
  }

  while(m--){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%d\n",sum[c][d] - sum[a-1][d] - sum[c][b-1] + sum[a-1][b-1]);
  }
  return 0;
}
