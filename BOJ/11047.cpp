#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;


int main(void){
  int n,k;
  scanf("%d %d",&n,&k);
  vector<int> val(n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&val[i]);
  }

  int ans = 0;

  for(int i = n-1 ; i >= 0 ; i--){
    ans += k/val[i];
    k %= val[i];
  }

  printf("%d\n",ans);
  return 0;
}
