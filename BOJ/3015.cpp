#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;


int main(void){
  int n;
  scanf("%d",&n);

  stack<pair<int,int> > stk;//1.height, 2.num

  long long ans = 0;

  for(int i = 0 ; i < n ; i++){
    int tmp, len = 1;
    scanf("%d",&tmp);

    while(!stk.empty() && stk.top().first < tmp){
      ans += stk.top().second;
      stk.pop();
    }

    if(!stk.empty()){
      if(stk.top().first == tmp){
        len = stk.top().second;
        stk.pop();
        if(!stk.empty()) ans++;
        ans += len;
        len++;
      }
      else ans += len;
    }
    stk.push(make_pair(tmp,len));
  }

  printf("%lld\n",ans);
  return 0;
}
