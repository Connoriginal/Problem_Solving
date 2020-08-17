//solved
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;


int main(void){
  int q;
  scanf("%d",&q);
  while(q--){
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
      scanf("%d",&arr[i]);
    }

    int pos = 0;
    while(pos < n){
      int nxt = min_element(arr.begin() + pos, arr.end()) - arr.begin();
      int el = arr[nxt];
      arr.erase(arr.begin() + nxt);
      arr.insert(arr.begin() + pos,el);
      if(pos == nxt) pos = nxt + 1;
      else pos = nxt;
    }

    for(auto &p : arr){
      printf("%d ",p);
    }
    printf("\n");
  }
  return 0;
}
