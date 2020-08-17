#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  int ans = 0;
  for(int i = 0 ; i < 2 ; i++){
    int sum = 0;
    for(int j = 0 ; j < 4 ; j++){
      int tmp;
      scanf("%d",&tmp);
      sum += tmp;
    }
    ans = max(sum,ans);
  }

  printf("%d\n",ans);
  return 0;
}
