#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int N;

int main(void){
	scanf("%d",&N);
	vector<int> vec(N);
	for(int i = 0 ; i < N ; i++)
		scanf("%d",&vec[i]);

	sort(vec.begin(),vec.end());

	int ans = 0;
	do{
		int tmp = 0;
		for(int i = 0 ; i < N-1 ; i++){
			tmp += (vec[i] > vec[i+1]) ? vec[i] - vec[i+1] : vec[i+1] - vec[i];
		}
		ans = max(ans,tmp);
	}while(next_permutation(vec.begin(),vec.end()));

	printf("%d\n",ans);
	return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int cal(vector<int> a){
  int ans = 0;
  for(int i = 0 ; i < a.size()-1 ; i++){
    ans += abs(a[i] - a[i+1]);
  }
  return ans;
}

int main() {
  int n;
  scanf("%d",&n);
  vector<int> a(n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }

  sort(a.begin(),a.end());

  int ans = cal(a);
  while(next_permutation(a.begin(),a.end())){
    ans = max(ans,cal(a));
  }

  printf("%d\n",ans);
  return 0;
}
*/
