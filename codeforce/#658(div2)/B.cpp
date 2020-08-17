#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);

    vector<int> vec(n);
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
      scanf("%d",&vec[i]);
      if(vec[i] == 1) cnt++;
    }

    bool flag = false;
    for(int i = 0 ; i < n ; i++){
      if(vec[i] == 1 && cnt > 0){
        flag = 1 - flag;
        cnt--;
      }else if(i == n-1){
        flag = 1 - flag;
      }else{
        cnt = 0;
      }
    }

    if(flag) printf("First\n");
    else printf("Second\n");
  }
  return 0;
}
