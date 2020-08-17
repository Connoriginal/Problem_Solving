#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int d[1001][1001];
int map[1001][1001];

int max3(int a, int b, int c){
  return max(a,max(b,c));
}

int main(void){
  int n,m;
  scanf("%d %d",&n,&m);

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      scanf("%d",&map[i][j]);
    }
  }

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      d[i][j] = max3(d[i-1][j],d[i][j-1],d[i-1][j-1]) + map[i][j];
    }
  }

  printf("%d\n",d[n][m]);
  return 0;
}
/* 방법2
int main(void){
  int n,m;
  scanf("%d %d",&n,&m);

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      scanf("%d",&map[i][j]);
    }
  }

  d[1][1] = map[1][1];

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      if(d[i+1][j] < d[i][j] + map[i+1][j])
        d[i+1][j] = d[i][j] + map[i+1][j];
      if(d[i][j+1] < d[i][j] + map[i][j+1])
        d[i][j+1] = d[i][j] + map[i][j+1];
      if(d[i+1][j+1] < d[i][j] + map[i+1][j+1])
        d[i+1][j+1] = d[i][j] + map[i+1][j+1];
    }
  }

  printf("%d\n",d[n][m]);
  return 0;
}
*/

/* 방법3 (방법1 에서 대각선 제외)

int d[1002][1002];
int map[1002][1002];

int main(void){
  int n,m;
  scanf("%d %d",&n,&m);

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      scanf("%d",&map[i][j]);
    }
  }

  d[1][1] = map[1][1];

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      d[i][j] = max(d[i-1][j],d[i][j-1]) + map[i][j];
    }
  }

  printf("%d\n",d[n][m]);
  return 0;
}
*/

/* 방법4 (top-down)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int d[1002][1002];
int map[1002][1002];

int go(int i, int j){
  if(i==1 && j == 1) return map[1][1];
  if(i < 1 || j < 1) return 0;
  if(d[i][j] >= 0) return d[i][j];
  d[i][j] = go(i-1,j) + map[i][j];
  int temp = go(i,j-1) + map[i][j];
  return d[i][j] = (d[i][j] > temp)? d[i][j] : temp;
}
int main(void){
  int n,m;
  scanf("%d %d",&n,&m);

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      scanf("%d",&map[i][j]);
    }
  }

  memset(d,-1,sizeof(d));

  printf("%d\n",go(n,m));
  return 0;
}
*/

/* 방법 5

int a[1002][1002];
int d[1002][1002];

int n,m;

int go(int x, int y){
  if(x > n || y > m) return 0;
  if(d[x][y] >= 0) return d[x][y];
  d[x][y] = go(x+1,y) + a[x][y];
  int temp = go(x,y+1) + a[x][y];
  return d[x][y] = d[x][y] > temp ? d[x][y] : temp;
}
int main(void){

  scanf("%d %d",&n,&m);

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      scanf("%d",&a[i][j]);
    }
  }

  memset(d,-1,sizeof(d));
  d[n][m] = a[n][m];

  printf("%d\n",go(1,1));
  return 0;
}
*/
