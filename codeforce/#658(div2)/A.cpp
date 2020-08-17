#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool check[1001];

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i < n ; i++){
      int tmp;
      scanf("%d",&tmp);
      check[tmp] = true;
    }

    bool flag = false;
    int ans = 1001;

    for(int i = 0 ; i < m ; i++){
      int tmp;
      scanf("%d",&tmp);
      if(check[tmp]){
        flag = true;
        ans = min(tmp,ans);
      }
    }

    if(flag){
      printf("YES\n%d %d\n",1,ans);
    }else{
      printf("NO\n");
    }

    memset(check,false,sizeof(check));
  }
  return 0;
}
