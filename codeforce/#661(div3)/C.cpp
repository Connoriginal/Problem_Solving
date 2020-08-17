#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int sum[101];
int arr[51];

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    memset(sum,0,sizeof(sum));
    memset(arr,0,sizeof(arr));
    int n;
    scanf("%d",&n);

    vector<int> vec;

    for(int i = 0 ; i < n ; i++){
      int tmp;
      scanf("%d",&tmp);
      if(arr[tmp] == 0) vec.push_back(tmp);
      arr[tmp]++;
    }

    for(int i = 0 ; i < vec.size() ; i++){
      for(int j = i ; j < vec.size() ; j++){
        int cur = vec[i];
        int next = vec[j];
        if(i == j && arr[cur] > 1){
          sum[cur * 2] += arr[cur] / 2;
        }

        if(i!=j){
          sum[cur + next] += min(arr[cur],arr[next]);
        }
      }
    }

    int ans = 0;
    for(int i = 0 ; i <= 100 ; i++) ans = max(ans,sum[i]);
    printf("%d\n",ans);
  }
  return 0;
}
