#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
  int n,m,k;
  scanf("%d %d %d",&n,&m,&k);
  if(!(m + k - 1 <= n && n <= m*k)){
    printf("-1\n");
    return 0;
  }

  vector<int> a(n);
  vector<int> b;

  for(int i = 0 ; i < n ; i++){
    a[i] = i+1;
  }

  b.push_back(0);b.push_back(k);
  m -= 1;
  n -= k;

  int gs = (m == 0) ? 0 : n/m;
  int r = (m == 0) ? 0 : n%m;

  for(int i = 0 ; i < m ; i++){
    b.push_back(b.back() + gs + ((r>0)? 1 : 0));
    if(r>0) r--;
  }


  for(int i = 0 ; i < b.size() - 1 ; i++){
    reverse(a.begin() + b[i], a.begin() + b[i+1]);
  }

  for(auto &p : a){
    cout << p << " ";
  }
  printf("\n");
  return 0;
}
