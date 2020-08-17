#include <iostream>
#include <cstdio>

using namespace std;

int a[1001];

int main(void){
  int l, n;
  scanf("%d %d",&l,&n);

  int ans1, max1 = 0;
  int ans2, max2 = 0;

  for(int i = 1 ; i <= n ; i++){
    int u,v;
    scanf("%d %d",&u,&v);
    if(v-u > max1){
      ans1 = i;
      max1 = v-u;
    }

    int tmp = 0;
    for(int j = u ; j <= v ; j++){
      if(a[j] == 0){
        a[j] = i;
        tmp++;
      }
    }

    if(max2 < tmp){
      ans2 = i;
      max2 = tmp;
    }
  }

  printf("%d\n%d\n",ans1,ans2);
  return 0;
}
