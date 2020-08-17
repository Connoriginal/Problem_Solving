#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define pb push_back
using namespace std;

int n,m,d;

int a[16][16];
bool b[16][16];


int count_enemy(void){
  int cnt = 0;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      if(b[i][j]) cnt++;
    }
  }
  return cnt;
}

pair<int,int> play(int idx, int cnt_attack){

  int min_len = 30, x = -1, y = -1;
  for(int i = 0 ; i < n - cnt_attack ; i++){
    for(int j = 0 ; j < m ; j++){
      int len = (n - cnt_attack - i) + abs(j - idx);
      if(a[i][j] && !b[i][j] && len <= d && min_len >= len){
        if(min_len == len){
          if(j < y){
            x = i; y = j;
          }
          continue;
        }
        min_len = len;
        x = i;
        y = j;
      }
    }
  }

  return make_pair(x,y);
}

int main(void){
  scanf("%d %d %d",&n,&m,&d);

  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      scanf("%d",&a[i][j]);
    }
  }

  vector<int> archer;
  for(int i = 0 ; i < m - 3 ; i++) archer.pb(0);
  for(int i = 0 ; i < 3 ; i++) archer.pb(1);

  int ans = 0;
  while(true){
    memset(b,false,sizeof(b));

    vector<pair<int,int> > check;

    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m; j++){
        if(archer[j]){
          check.pb(play(j,i));
        }
      }
      while(!check.empty()){
        int x = check.back().first, y = check.back().second;
        if(x != -1 && y != -1) b[x][y] = true;
        check.pop_back();
      }
    }

    ans = max(ans,count_enemy());
    if(!next_permutation(archer.begin(),archer.end())) break;
  }

  printf("%d\n",ans);
  return 0;
}
