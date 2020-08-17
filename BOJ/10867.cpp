#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main(void){
  scanf("%d",&n);
  vector<int> vec(n);
  for(int i = 0 ; i < n ; i++) scanf("%d",&vec[i]);

  sort(vec.begin(),vec.end());

  int prev = vec[0];
  printf("%d ",prev);
  for(int i = 1 ; i < n ; i++){
    int cur = vec[i];
    if(cur > prev){
      printf("%d ",cur);
      prev = cur;
    }
  }
  printf("\n");
  return 0;
}
