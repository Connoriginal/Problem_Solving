#include <iostream>
#include <cstdio>

using namespace std;


int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
      int tmp;
      scanf("%d",&tmp);
      sum += tmp;
    }
    int mod = sum / n;

    int ans = (sum > n*mod) ? mod+1 : mod;

    printf("%d\n",ans);
  }
  return 0;
}
