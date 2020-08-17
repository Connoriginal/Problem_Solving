//top-down
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a[2002];
int d[2002][2002];

int go(int x, int y){
  if(x == y) return 1;
  if(d[x][y] >= 0) return d[x][y];
  if(x > y) return 1;

  if(a[x] != a[y]){
    return d[x][y] = 0;
  }
  return d[x][y] = go(x+1,y-1);
}
int main(void){
  int n;
  scanf("%d",&n);
  for(int i = 1 ; i <= n ; i++){
    scanf("%d",&a[i]);
  }

  memset(d,-1,sizeof(d));

  int t;
  scanf("%d",&t);
  while(t--){
    int s,e;
    scanf("%d %d",&s,&e);
    printf("%d\n",go(s,e));
  }
  return 0;
}
/* bottom-up
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a[2002];
int d[2002][2002];

int main(void){
  int n;
  scanf("%d",&n);
  for(int i = 1 ; i <= n ; i++){
    scanf("%d",&a[i]);
    d[i][i] = 1;
  }

  for(int i = 1 ; i < n ; i++){
    if(a[i] == a[i+1]) d[i][i+1] = 1;
  }

  for(int k = 2 ; k < n ; k++){
    for(int i = 1 ; i < n - k + 1 ; i++){
      if(a[i] == a[i+k] && d[i+1][i+k-1]){
        d[i][i+k] = 1;
      }
    }
  }


  int t;
  scanf("%d",&t);
  while(t--){
    int s,e;
    scanf("%d %d",&s,&e);
    printf("%d\n",d[s][e]);
  }
  return 0;
}
*/
