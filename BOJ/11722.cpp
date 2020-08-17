#include <iostream>
#include <cstdio>

using namespace std;

int d[1001];
int a[1001];

int main(void){
  int n;
  scanf("%d",&n);

  for(int i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
    d[i] = 1;
  }

  for(int i = 1 ; i < n ; i++){
    for(int j = 0 ; j < i ; j++){
      if(a[i] < a[j] && d[i] < d[j] + 1){
        d[i] = d[j] + 1;
      }
    }
  }

  int ans = 0 ;
  for(int i = 0 ; i < n ; i++){
    ans = max(ans,d[i]);
  }

  printf("%d\n",ans);
  return 0;
}
