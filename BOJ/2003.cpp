#include <iostream>
#include <cstdio>

using namespace std;

int arr[10001];

int main(void){
  int n,m;
  scanf("%d %d",&n,&m);

  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }

  int sp = 0, ep = 0, sum = 0, cnt = 0;

  while(sp < n){
    if(sum >= m){
      sum -= arr[sp++];
    }
    else{
      if(ep == n) break;
      sum += arr[ep++];
    }
    if(sum == m) cnt++;
  }
  printf("%d\n",cnt);
}
