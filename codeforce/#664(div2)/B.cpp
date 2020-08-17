#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool map[102][102];
int n,m,sx,sy;
bool row[102];

bool check(int x){
  for(int i = 1 ; i <= m ; i++){
    if(!map[x][i]) return false;
  }
  return true;
}

int check_row(){
  for(int i = 1 ; i <= n ; i++){
    if(!row[i]) return i;
  }
  return -1;
}
int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m >> sx >> sy;

  int x = sx, y = sy;

  while(true){
    bool flag = check(x);
    if(!flag){
      cout << x << ' ' << y << '\n';
      map[x][y] = true;
      for(int i = 1 ; i <= m ; i++){
        if(!map[x][i]){
          cout << x << ' ' << i << '\n';
          map[x][i] = true;
          y = i;
        }
      }
      row[x] = true;
    }

    x = check_row();
    if(x == -1) break;
  }

  return 0;
}
