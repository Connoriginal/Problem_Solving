#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  for(int case_num = 1 ;; case_num++){
    int l, p, v;
    scanf("%d %d %d",&l,&p,&v);
    if(l == 0 && p == 0 & v ==0) break;

    int ans = (v/p) *l;
    ans += ((v%p) > l) ? l : v%p;

    printf("Case %d: %d\n",case_num,ans);
  }
  return 0;
}
