//배열사용 (시간은 같음, 메모리더 낮음)
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


int t;

int main(void){
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
      scanf("%d",&a[i]);
    }

    int ans = 0;
    int right_min = INT_MAX;

    for(int i = n-1; i >= 0 ; i--){
      if(a[i] > right_min){
        ans++;
      }
      right_min = min(a[i],right_min);
    }

    printf("%d\n",ans);
  }

  return 0;
}
