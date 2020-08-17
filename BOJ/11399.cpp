#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main(void){
  int n;
  scanf("%d",&n);

  vector<int> a(n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }

  sort(a.begin(),a.end());

  vector<int> b(n);
  int ans = 0;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j <= i ; j++){
      b[i] += a[j];
    }
    ans += b[i];
  }

  printf("%d\n",ans);
  return 0;
}
