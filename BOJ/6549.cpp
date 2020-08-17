#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;


int main(void){
  int n;
  while(true){
    scanf("%d",&n);
    if(n==0) break;

    stack<pair<int,long long> > stk;
    long long ans = 0;

    for(int i = 0 ; i < n ; i++){
      long long tmp;
      scanf("%lld",&tmp);

      while(!stk.empty() && tmp < stk.top().second){
        long long h = stk.top().second;
        long long w = i;
        stk.pop();
        if(!stk.empty()) w -= (stk.top().first + 1);

        ans = max(ans,h*w);
      }
      stk.push(make_pair(i,tmp));
    }

    while(!stk.empty()){
      long long h = stk.top().second;
      long long w = n;
      stk.pop();
      if(!stk.empty()) w -= (stk.top().first + 1);

      ans = max(ans,h*w);
    }

    printf("%lld\n",ans);
  }
  return 0;
}
