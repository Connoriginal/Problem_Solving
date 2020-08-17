#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int a[51][51];
int b[51][51];
int n, m;

void go(int x, int y){
  for(int i = x ; i < x + 3 ; i++){
    for(int j = y ; j < y + 3 ; j++){
      a[i][j] = 1 - a[i][j];
    }
  }
}

bool check(void){
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      if(a[i][j] != b[i][j]) return false;
    }
  }

  return true;
}

int main(void){
  scanf("%d %d",&n,&m);

  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      scanf("%1d",&a[i][j]);
    }
  }

  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      scanf("%1d",&b[i][j]);
    }
  }

  // change
  int ans = 0;
  for(int i = 0 ; i < n-2 ; i++){
    for(int j = 0 ; j < m - 2 ; j++){
      if(a[i][j] != b[i][j]){
        go(i,j);
        ans++;
      }
    }
  }

  if(check()){
    printf("%d\n",ans);
  }
  else{
    printf("-1\n");
  }
  return 0;
}
