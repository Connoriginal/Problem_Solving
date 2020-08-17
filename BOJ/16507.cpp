#include <iostream>
#include <cstdio>

using namespace std;

int a[1001][1001], sum[1001][1001];
int main(void){
  int r,c,q;
  scanf("%d %d %d",&r,&c,&q);

  for(int i = 1 ; i <= r ; i++){
    for(int j = 1 ; j <= c ; j++){
      scanf("%d",&a[i][j]);
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
    }
  }
  while(q--){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%d\n",(sum[c][d] -sum[a-1][d] - sum[c][b-1] + sum[a-1][b-1]) / ((c-a+1) * (d-b+1)));
  }
  return 0;
}
