#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main(void){
  scanf("%d",&n);
  vector<int> vec(n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&vec[i]);
  }

  sort(vec.begin(),vec.end());

  int ans = 0;
  for(int i = 0 ; i < vec.size() ; i++){
    if(vec[i] > ans + 1) break;
    ans += vec[i];
  }
  printf("%d\n",ans+1);
  return 0;
}
