#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

int main(void){
  int n,m;
  scanf("%d %d",&n,&m);

  vector<int> vec(n);
  deque<pair<int,int> > dq;

  for(int i = 0 ; i < n ; i++){
    scanf("%d",&vec[i]);
    if(i == 0) dq.push_back(make_pair(vec[i],i));
    else if(i < 2*m - 1){
      while(!dq.empty() && dq.back().first < vec[i]) dq.pop_back();
      dq.push_back(make_pair(vec[i],i));
    }
  }

  int l = 0, r = 2*m - 2;

  while(r < n){
    while(!dq.empty() && !(l <= dq.front().second && dq.front().second <= r)){
      dq.pop_front();
    }
    printf("%d ",dq.front().first);
    l++;
    r++;
    while(!dq.empty() && dq.back().first < vec[r]) dq.pop_back();
    dq.push_back(make_pair(vec[r],r));
  }
  printf("\n");
  return 0;
}
