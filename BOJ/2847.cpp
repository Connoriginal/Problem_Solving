#include <iostream>
#include <cstdio>

using namespace std;

int n;
int a[101];

int main(void){
  scanf("%d",&n);
  for(int i = 1 ; i <= n ; i++){
    scanf("%d",&a[i]);
  }

  int ans = 0;

  for(int i = n-1 ; i >= 1 ; i--){
    if(a[i] >= a[i+1]){
      ans += a[i] - a[i+1] + 1;
      a[i] = a[i+1] - 1;
    }
  }

  printf("%d\n",ans);
  return 0;
}
