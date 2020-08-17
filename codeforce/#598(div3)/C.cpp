//solved
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;


int main(void){
  int n,m,d;
  scanf("%d %d %d",&n,&m,&d);
  vector<int> arr(m);
  for(int i = 0 ; i < m ; i++){
    scanf("%d",&arr[i]);
  }

  vector<int> ans(n+2);

  for(int pos = n, i = m-1 ; i >= 0 ; i--){
    for(int len = 0 ; len < arr[i] ; len++){
      ans[pos-len] = i+1;
    }
    pos -= arr[i];
  }

  int now = 0;
  while(true){
    while(now + 1 < n + 1 && ans[now+1]>0) now++;

    if(now + d >= n + 1) break;

    if(ans[now+d] == 0){
      int lpos = -1;
      for(int i = now + d ; i < n+2 ; i++){
        if(ans[i] > 0){
          lpos = i;
          break;
        }
      }

      if(lpos == -1){
        printf("NO\n");
        return 0;
      }

      int rpos = -1;

      for(int i = n ; i > 0 ; i--){
        if(ans[i] == ans[lpos]){
          rpos = i;
          break;
        }
      }

      while(ans[now + d] == 0){
        swap(ans[lpos-1],ans[rpos]);
        lpos--;rpos--;
      }
    }

    now += d;
  }

  printf("YES\n");
  for(int i = 1 ; i < n+1 ; i++){
    printf("%d ",ans[i]);
  }
  printf("\n");
  return 0;
}
