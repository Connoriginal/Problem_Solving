#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  int n;
  while(scanf("%d",&n)){
    if(n == 0) break;
    int prev, cur;
    scanf("%d",&prev);
    printf("%d ",prev);
    for(int i = 1 ; i < n ; i++){
      scanf("%d",&cur);
      if(cur != prev){
        printf("%d ",cur);
        prev = cur;
      }
    }
    printf("$\n");
  }
  return 0;
}
