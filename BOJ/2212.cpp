#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;

int main(void){
  scanf("%d %d",&n,&k);
  vector<int> vec;

  for(int i = 0 ; i < n ; i++){
    int tmp;
    scanf("%d",&tmp);
    vec.push_back(tmp);
  }

  sort(vec.begin(),vec.end());

  //중복제거
  vec.erase(unique(vec.begin(), vec.end()),vec.end());

  vector<int> len;

  for(int i = 1 ; i < vec.size() ; i++){
    len.push_back(vec[i] - vec[i-1]);
  }

  sort(len.begin(),len.end(),greater<int>());

  int ans = 0;
  for(int i = k-1 ; i < len.size() ; i++){
    ans += len[i];
  }

  printf("%d\n",ans);
  return 0;
}
