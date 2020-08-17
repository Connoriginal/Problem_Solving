//top-down
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int a[502][502];
long long d[502][502];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int n,m;

long long go(int x, int y){
  if(x == n && y == m) return 1;
  if(d[x][y] >= 0) return d[x][y];

  d[x][y] = 0;
  for(int k = 0 ; k < 4 ; k++){
    int nx = x + dx[k], ny = y + dy[k];
    if(0 < nx && nx <= n && 0 < ny && ny <=m){
      if(a[nx][ny] < a[x][y]){
        d[x][y] += go(nx,ny);
      }
    }
  }
  return d[x][y];
}

int main(void){

  scanf("%d %d",&n,&m);

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      scanf("%d",&a[i][j]);
      d[i][j] = -1;
    }
  }


  printf("%lld\n",go(1,1));
  return 0;
}
/* bottom-up
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Cell{
  int row,column,val;
};

int a[502][502];
long long d[502][502];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int n,m;

bool cmp(Cell &u, Cell &v){
  return u.val < v.val;
}

int main(void){
  scanf("%d %d",&n,&m);
  vector<Cell> v;

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      scanf("%d",&a[i][j]);
      v.push_back({i,j,a[i][j]});
    }
  }

  sort(v.begin(),v.end(),cmp);

  d[n][m] = 1;
  for(int i = 0 ; i < v.size() ; i++){
    int x = v[i].row, y = v[i].column;
    for(int k = 0 ; k < 4 ; k++){
      int nx = x + dx[k], ny = y + dy[k];
      if(0 < nx && nx <= n && 0 < ny && ny <= m){
        if(a[nx][ny] < a[x][y]){
          d[x][y] += d[nx][ny];
        }
      }
    }
  }

  printf("%lld\n",d[1][1]);
  return 0;
}
*/
