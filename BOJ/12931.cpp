#include <iostream>
#include <cstdio>

using namespace std;

int a[50];
int n;

bool check(void){
  for(int i = 0 ; i < n ; i++){
    if(a[i] > 0 ) return false;
  }
  return true;
}

int main(void){

  scanf("%d",&n);

  long long ans = 0;
  for(int i = 0 ; i < n ; i++){
    int tmp;
    scanf("%d",&tmp);

    if(tmp % 2 == 1){
      tmp--;
      ans++;
    }
    a[i] = tmp;
  }

  while(!check()){
    ans++;
    for(int i = 0 ; i < n ; i++){
      a[i] /= 2;
      if(a[i] % 2 == 1){
        a[i]--;
        ans++;
      }
    }
  }

  printf("%lld\n",ans);

  return 0;
}
