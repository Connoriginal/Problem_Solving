//stack 사용(시간은 같움, 메모리 높음)
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int t,n;
stack<int> stk;

int main(void){
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    int ans = 0;

    for(int i = 0 ; i < n ; i++){
      int tmp;
      scanf("%d",&tmp);


      while(!stk.empty() && stk.top()>tmp){
        ans++;
        stk.pop();
      }

      stk.push(tmp);
    }

    printf("%d\n",ans);
    while(!stk.empty()){
      stk.pop();
    }

  }
  return 0;
}
