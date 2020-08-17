#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);
    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++){
      scanf("%d",&arr[i]);
    }

    sort(arr.begin(),arr.end());

    bool ans = true;
    for(int i = 0 ; i < n-1 ; i++){
      if(arr[i+1] - arr[i] > 1){
        ans = false;
        break;
      }
    }

    if(ans) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
