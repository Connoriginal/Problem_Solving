#include <iostream>
#include <cstdio>

using namespace std;

int a[1001];
int d1[1001];
int d2[1001];

int main(void){
  int n;
  scanf("%d",&n);

  for(int i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
    d1[i] = 1; d2[i] = 1;
  }

  //d1
  for(int i = 1 ; i < n ; i++){
    for(int j = 0 ; j < i ; j++){
      if(a[i] > a[j] && d1[i] < d1[j] + 1){
        d1[i] = d1[j] + 1;
      }
    }
  }

  //d2
  for(int i = n-2 ; i >= 0 ; i--){
    for(int j = n-1 ; j > i ; j--){
      if(a[i] > a[j] && d2[i] < d2[j] + 1){
        d2[i] = d2[j] + 1;
      }
    }
  }

  int ans = d1[0] + d2[0] - 1;
  for(int i = 1 ; i < n ; i++){
    ans = max(ans,d1[i] + d2[i] - 1);
  }

  printf("%d\n",ans);
  return 0;
}
