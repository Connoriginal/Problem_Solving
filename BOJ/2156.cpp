#include <iostream>
#include <cstdio>

using namespace std;

int p[10001];
int d[10001][3];

int main(void){
  int n;
  scanf("%d",&n);
  for(int i = 1 ; i <= n ; i++){
    scanf("%d",&p[i]);
  }

  d[1][1] = p[1];

  for(int i = 2 ; i <= n ; i++){
    d[i][0] = max(max(d[i-1][0], d[i-1][1]), d[i-1][2]);
    d[i][1] = d[i-1][0] + p[i];
    d[i][2] = d[i-1][1] + p[i];
  }

  int ans = 0;
  for(int i = 0 ; i < 3 ; i++) ans = max(d[n][i],ans);

  printf("%d\n",ans);
  return 0;
}
