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


int N;
int arr[500001];
int tmp[500001];


long long solve(int start,int end){
	if(start == end)
		return 0;
	int mid = (start + end)/2;
	long long ans = solve(start,mid) + solve(mid + 1, end);

	int i = start, j = mid + 1, k = 0;
	while(i <= mid || j <= end){
		if(i <= mid && (j > end || arr[i] <= arr[j])){
			tmp[k++] = arr[i++];
		}
		else{
			tmp[k++] = arr[j++];
			ans += (long long)(mid - i + 1);
		}
	}

	for(int i = start ; i <= end ; i++)
		arr[i] = tmp[i-start];

	return ans;
}

int main(void){
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++)
		scanf("%d",&arr[i]);

	long long ans = solve(0,N-1);
	printf("%lld\n",ans);
	return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int arr[500001];
int sortarr[500001];

long long go(int start, int end){
  if(start + 1 == end) return 0;

  int mid = (start + end)/2;
  long long ans = go(start,mid) + go(mid,end);
  int i = start, j = mid, k = start;

  while(i < mid || j < end){
    if(i < mid && (j >= end || arr[i] <= arr[j])){
      sortarr[k++] = arr[i++];
    }
    else{
      sortarr[k++] = arr[j++];
      ans += (long long)mid - i;
    }
  }

  for(int i = start ; i < end ; i++){
    arr[i] = sortarr[i];
  }
  return ans;
}

int main(void){
  int n;
  scanf("%d",&n);

  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }

  printf("%lld\n",go(0,n));
  return 0;
}
*/
