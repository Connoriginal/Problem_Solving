#include <iostream>
#include <cstdio>


using namespace std;

int a[101];

int main(void){
  int n,k;
  scanf("%d %d",&n,&k);

  int pt = 0;

  bool ans = true;

  for(int i = 0 ; i < n ; i++){
    bool flag = false;
    int tmp;
    scanf("%d",&tmp);

    for(int j = 0 ; j < pt ; j++){
      if(a[j] < tmp){
        a[j] = tmp;
        flag = true;
        break;
      }
    }

    if(!flag){
      if(pt < k){
        a[pt++] = tmp;
      }else{
        ans = false;
        break;
      }
    }
  }

  if(ans) printf("YES\n");
  else printf("NO\n");

  return 0;
}
