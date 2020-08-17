#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dp[101][101][101];

int go(int a, int b, int c){
  if(dp[a][b][c] > 0) return dp[a][b][c];
  if(b < 1) return 0;

  if(a >= 1 && b >= 2){
    int temp = 3 + go(a-1,b-2,c);
    if(temp > dp[a][b][c]){
      dp[a][b][c] = temp;
    }
  }

  if(b >= 1 && c >= 2){
    int temp = 3 + go(a,b-1,c-2);
    if(temp > dp[a][b][c]){
      dp[a][b][c] = temp;
    }
  }
  return dp[a][b][c];
}

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);

    printf("%d\n",go(a,b,c));

  }
  return 0;
}
