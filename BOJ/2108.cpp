#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int a[8001];

int main(void){
  int n;
  scanf("%d",&n);

  vector<int> vec(n);

  double sum = 0;

  for(int i = 0 ; i < n ; i++){
    scanf("%d",&vec[i]);
    sum += vec[i];
    a[vec[i] + 4000]++;
  }

  sort(vec.begin(),vec.end());

  //산술평균
  printf("%d\n",(int)round(sum/n));

  //중앙값
  printf("%d\n",vec[n/2]);


  //최빈값
  int ans, max = 0, num = 0;
  for(int i = 0 ; i < n ; i++){
    if(max < a[vec[i] + 4000]){
      max = a[vec[i] + 4000];
      ans = vec[i];
      num = 1;
    }else if(max == a[vec[i] + 4000]){
      if(num == 1 && ans != vec[i]){
        ans = vec[i];
        num++;
      }
    }
  }

  printf("%d\n",ans);
  //범위
  printf("%d\n",vec[n-1] - vec[0]);
  return 0;
}
