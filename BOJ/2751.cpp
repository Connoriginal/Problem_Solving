#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int n;
  scanf("%d",&n);
  vector<int> vec(n);

  for(int i = 0 ; i < n ; i++){
    scanf("%d",&vec[i]);
  }

  sort(vec.begin(),vec.end());

  for(int i = 0 ; i < n ; i++){
    printf("%d\n",vec[i]);
  }

  return 0;
}
