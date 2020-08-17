#include <iostream>
#include <cstdio>

using namespace std;

int a[301];
int d[301][2];

int main(void){
  int n;
  scanf("%d",&n);

  for(int i = 1 ; i <= n ; i++){
    scanf("%d",&a[i]);
  }

  d[1][0] = a[1];

  for(int i = 2 ; i <= n ; i++){
    d[i][0] = max(d[i-2][0],d[i-2][1]) + a[i];
    d[i][1] = d[i-1][0] + a[i];
  }

  printf("%d\n",max(d[n][0],d[n][1]));
  return 0;
}
