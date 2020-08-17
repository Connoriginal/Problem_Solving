#include <iostream>
#include <cstdio>

using namespace std;

int p[100001][2];
int d[100001][2];

int t;

int main(void){
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);

    for(int i = 0 ; i < 2 ; i++){
      for(int j = 1 ; j <= n ; j++){
        scanf("%d",&p[j][i]);
      }
    }

    d[1][0] = p[1][0];d[1][1] = p[1][1];
    d[2][0] = d[1][1] + p[2][0]; d[2][1] = d[1][0] + p[2][1];

    for(int i = 3 ; i <= n ; i++){
      d[i][0] = max(max(d[i-2][0],d[i-2][1]),d[i-1][1]) + p[i][0];
      d[i][1] = max(max(d[i-2][0],d[i-2][1]),d[i-1][0]) + p[i][1];
    }

    printf("%d\n",max(d[n][0],d[n][1]));

  }

  return 0;
}
