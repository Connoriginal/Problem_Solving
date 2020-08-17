#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



int main(void){
  int n, m;
  scanf("%d %d",&n,&m);
  vector<int> a(m+1);
  for(int i = 1 ; i <= m ; i++){
    scanf("%d",&a[i]);
  }

  if(n <= m){
    printf("%d\n",n);
    return 0;
  }

  long long left = 0, right = 2000000000LL*1000000LL;
  while(left <= right){
    long long mid = (left + right)/2;
    long long cnt = m;
    for(int i = 1 ; i <= m ; i++){
      cnt += mid/a[i];
    }
    long long start = cnt;
    for(int i = 1 ; i <= m ; i++){
      if(mid%a[i] == 0) start--;
    }

    start++;

    if(start > n){
      right = mid - 1;
    }
    else if(cnt < n){
      left = mid + 1;
    }
    else{
      for(int i = 1 ; i <= m ; i++){
        if(mid % a[i] == 0){
          if(start == n){
            printf("%d\n",i);
            return 0;
          }
          start++;
        }
      }
    }
  }
  return 0;
}
