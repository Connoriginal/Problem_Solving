#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
  int n;
  scanf("%d",&n);

  int ans = 0;

  for(int i = 3 ; i <= n ; i+=3){
    for(int j = 3 ; j <= n - i ; j+=3){
      if((n-i-j) % 3 == 0 && (n-i-j) >= 3){
        ans++;
      }
    }
  }

  printf("%d\n",ans);
  return 0;
}
