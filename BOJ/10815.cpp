#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int arr[500001];

int binsearch(int start, int end, int idx){
  int left = start, right = end - 1, mid = (left + right) / 2;
  while(left <= right){
    if(arr[mid] == idx){
      return 1;
    }
    if(idx > arr[mid]){
      left = mid + 1;
    }
    else{
      right = mid - 1;
    }
    mid = (left + right)/2;
  }
  return 0;
}

int main(void){
  int n;
  scanf("%d",&n);

  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }

  sort(arr,arr+n);

  int m;
  scanf("%d",&m);
  while(m--){
    int temp;
    scanf("%d",&temp);
    printf("%d ",binsearch(0,n,temp));
  }
  printf("\n");
  return 0;
}


/* stl 사용
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

  int m;
  scanf("%d",&m);
  while(m--){
    int temp;
    scanf("%d",&temp);
    printf("%d ",binary_search(a.begin(),a.end(),temp));
  }
  printf("\n");
  return 0;
}
*/
