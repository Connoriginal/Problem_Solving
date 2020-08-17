#include <iostream>
#include <cstdio>

using namespace std;

int k;
int a[100001];

int main(void){
  scanf("%d",&k);

  int pt = 0;
  while(k--){
    int tmp;
    scanf("%d",&tmp);
    if(tmp != 0) a[pt++] = tmp;
    else{
      if(pt > 0) pt--;
    }
  }

  int ans = 0;
  for(int i = 0 ; i < pt ; i++) ans += a[i];

  printf("%d\n",ans);
  return 0;
}
