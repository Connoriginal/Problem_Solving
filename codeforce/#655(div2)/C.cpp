#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int check(vector<int> a, int l, int r){
  if(l >= r) return 0;
  int ans = 1;
  for(int i = l ; i <= r ; i++){
    if(a[i] == i) ans = 2;
  }
  return ans;
}

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);

    vector<int> vec(n+1);
    for(int i = 1 ; i <= n ; i++) scanf("%d",&vec[i]);

    int l = 1, r = n;
    while(vec[l] == l) l++;
    while(vec[r] == r) r--;

    printf("%d\n",check(vec,l,r));
  }
  return 0;
}
