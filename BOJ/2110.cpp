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


int N,C;

bool check(vector<long long> vec, long long mid){
	int cnt = 0;
	long long ran = 0;
	for(int i = 0 ; i < vec.size() ; i++){
		if(vec[i] >= ran){
			ran = vec[i] + mid;
			cnt++;
		}
	}

	if(cnt >= C) return true;
	return false;
}

int main(void){
	scanf("%d %d",&N,&C);
	vector<long long> vec(N);
	for(int i = 0 ; i < N ; i++)
		scanf("%lld",&vec[i]);

	sort(vec.begin(),vec.end());
	long long left = vec[0], right = vec.back();
	long long ans = 0;

	while(left <= right){
		long long mid = (left+right)/2;
		if(check(vec,mid)){
			if(mid > ans) ans = mid;
			left = mid + 1;
		}
		else{
			right = mid-1;
		}
	}

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


int main(void){
  int n,k;
  scanf("%d %d",&n,&k);

  vector<int> a(n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }

  sort(a.begin(),a.end());

  int left = 1, right = a[n-1] - a[0];
  int ans = 1;

  while(left <= right){
    int mid = (left + right)/2;

    int cnt = 1;
    int temp = a[0];
    for(int i = 0 ; i < n ; i++){
      if(a[i] - temp >= mid){
        cnt++;
        temp = a[i];
      }
    }

    if(cnt >= k){
      if(ans < mid) ans = mid;
      left = mid + 1;
    }
    else{
      right = mid - 1;
    }
  }

  printf("%d\n",ans);

  return 0;
}
*/
