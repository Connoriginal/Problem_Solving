#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int n;
  scanf("%d",&n);

  vector<long long> vec(n);

  for(int i = 0 ; i < n ; i++){
    scanf("%lld",&vec[i]);
  }

  sort(vec.begin(),vec.end());

  long long num = vec[0];
  int ans = 1;
  int cur = 1;

  for(int i = 1 ; i < n ; i++){
    if(vec[i] == vec[i-1]){
      cur++;
      if(cur > ans){
        num = vec[i];
        ans = cur;
      }
    }
    else{
      cur = 1;
    }
  }

  printf("%lld\n",num);
  return 0;
}

/* map 사용

int N;

int main(void){
	scanf("%d",&N);
	map<long long ,int> mp;
	while(N--){
		long long tmp;
		scanf("%lld",&tmp);
		mp[tmp] += 1;
	}

	int cnt = 0;
	long long ans = 0;
	for(auto &p : mp){
		if(p.second > cnt){
			cnt = p.second;
			ans = p.first;
		}
		else if(p.second == cnt && p.first < ans)
			ans = p.first;
	}

	printf("%lld\n",ans);
	return 0;
}
*/
