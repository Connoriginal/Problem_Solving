#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int a[501];
int s[501];
int d[501][501];

int go(int x, int y){
  if(x == y) return 0;
  if(d[x][y] != -1) return d[x][y];

  for(int k = x ; k < y ; k++){
    int tmp = go(x,k) + go(k+1,y) + s[y] - s[x-1];
    if(d[x][y] == -1 || d[x][y] > tmp){
      d[x][y] = tmp;
    }
  }

  return d[x][y];
}

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    memset(d,-1,sizeof(d));
    memset(s,0,sizeof(s));

    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++){
      scanf("%d",&a[i]);
      s[i] = s[i-1] + a[i];
    }

    printf("%d\n",go(1,n));

  }
  return 0;
}
