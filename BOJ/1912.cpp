#include <iostream>
#include <cstdio>

using namespace std;

int a[100000];
int d[100000];

int main(void){
  int n;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
    d[i] = a[i];
  }

  for(int i = 1 ; i < n ; i++){
    d[i] = max(d[i], d[i-1] + a[i]);
  }

  int ans = d[0];
  for(int i = 1 ; i < n ; i++){
    ans = max(ans,d[i]);
  }

  printf("%d\n",ans);
  return 0;
}
