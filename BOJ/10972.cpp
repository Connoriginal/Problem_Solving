#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int arr[10001];

void swap(int* arr, int x, int y){
	int tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;
	return;
}

bool next_per(int* arr, int n){
	int i = n-1;
	while(i > 0 && arr[i-1] > arr[i]) i--;
	if(i == 0) return false;
	int j = n-1;
	while(arr[i-1] > arr[j]) j--;
	swap(arr,i-1,j);

	reverse(arr + i , arr + n);
	return true;
}

int main(void){
	int N;
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++)
		scanf("%d",&arr[i]);

	if(!next_per(arr,N)){
		printf("-1\n");
		return 0;
	}

	for(int i = 0 ; i < N ; i++)
		printf("%d ",arr[i]);
	printf("\n");

	return 0;
}
/* for문 버전
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int a[10001];

void swap(int *arr, int idx1, int idx2){
  int tmp = arr[idx1];
  arr[idx1] = arr[idx2];
  arr[idx2] = tmp;
}

bool next_per(int *arr, int start, int end){
  int idx1 = -1;
  for(int i = start  ; i < end - 1 ; i++){
    if(arr[i] < arr[i+1] && i + 1 > idx1){
      idx1 = i;
    }
  }
  if(idx1 == -1) return false;

  int idx2 = idx1 + 1;
  for(int i = idx2 ; i < end ; i++){
    if(arr[idx1] < arr[i] && i > idx2){
      idx2 = i;
    }
  }
  swap(arr,idx1,idx2);
  reverse(a+idx1+1,a+end);
  return true;
}
int main(void){
  int n;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }

  if(next_per(a,0,n)){
    for(int i = 0 ; i < n ; i++){
      printf("%d ",a[i]);
    }
    printf("\n");
  }
  else{
    printf("-1\n");
  }


  return 0;
}
*/

/* stl 사용 버전
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int a[10001];

int main(void){
  int n;
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }

  if(next_permutation(a,a+n)){
    for(int i = 0 ; i < n ; i++){
      printf("%d ",a[i]);
    }
    printf("\n");
  }
  else{
    printf("-1\n");
  }
  return 0;
}
*/
