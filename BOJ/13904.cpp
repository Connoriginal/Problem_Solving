#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[1001];

bool cmp(const pair<int,int> &u, const pair<int,int> &v){
  if(u.second == v.second){
    return u.first < v.first;
  }
  return u.second > v.second;
}

int main(void){
  int n;
  scanf("%d",&n);

  vector<pair<int,int> > vec(n);

  for(int i = 0 ; i < n ; i++) scanf("%d %d",&vec[i].first,&vec[i].second);

  sort(vec.begin(),vec.end(),cmp);

  int ans = 0;
  for(int i = 0 ; i < n ; i++){
    int pt = vec[i].first;
    while(a[pt] != 0) pt--;
    if(pt != 0){
      a[pt] = vec[i].second;
      ans += vec[i].second;
    }
  }

  printf("%d\n",ans);
  return 0;
}
