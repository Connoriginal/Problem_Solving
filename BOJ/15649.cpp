#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int fac[10] = {1,};

int main(void){
  int n,m;
  scanf("%d %d",&n,&m);

  vector<int> vec(n);
  for(int i = 1 ; i <= n ; i++) vec[i-1] = i;

  fac[1] = 1;
  for(int i = 2 ; i <= n ; i++){
    fac[i] = fac[i-1] * i;
  }

  int mod = fac[n-m];
  int cnt = 0;
  while(true){
    if(cnt % mod == 0){
      for(int i = 0 ; i < m ; i++) printf("%d ",vec[i]);
      printf("\n");
    }
    cnt++;
    if(!next_permutation(vec.begin(),vec.end())) break;
  }
  return 0;
}
