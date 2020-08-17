#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int n,k;
int a[101];
int d[10002];

int main(void){
  scanf("%d %d",&n,&k);

  int len = 1;
  for(int i = 1 ; i <= n ; i++){
    int tmp;
    scanf("%d",&tmp);
    for(int j = 1 ; j < len ; j++){
      if(tmp == a[j]) continue;
    }
    a[len++] = tmp;
  }


  for(int i = 0 ; i <= k ; i++) d[i] = -1;

  d[0] = 0;
  for(int i = 1 ; i < len ; i++){
    for(int j = 0 ; j <= k ; j++){
      if(j - a[i] >= 0 && d[j-a[i]] != -1){
        if(d[j] == -1 || d[j] > d[j-a[i]] + 1){
          d[j] = d[j-a[i]] + 1;
        }
      }
    }
  }

  printf("%d\n",d[k]);
  return 0;
}
