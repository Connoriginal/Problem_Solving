#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int dp[1001], p[1001];

int main(void){
	scanf("%d",&T);

	for(int i = 1 ; i < T + 1 ; i++)
		scanf("%d",&p[i]);

	for(int i = 1 ; i < T + 1 ; i++){
		for(int j = 1 ; j <= i ; j++){
			dp[i] = max(dp[i],dp[i-j] + p[j]);
		}
	}

	printf("%d\n",dp[T]);
	return 0;
}
/* Top-down
#include <iostream>
#include <cstdio>

using namespace std;

int d[1001];
int p[1001];
int n;

int dp(int x){
  if(x == 0) return 0;
  if(d[x] > 0) return d[x];

  for(int i = 1 ; i <= x ; i++){
    int temp = dp(x-i) + p[i];
    if(d[x] < temp) d[x] = temp;
  }
  return d[x];
}

int main(void){
  scanf("%d",&n);
  for(int i = 1; i <= n ; i++){
    scanf("%d",&p[i]);
  }

  printf("%d\n",dp(n));
  return 0;
}
*/


// vector 배열 사용
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int T;



int main(void){
	scanf("%d",&T);

	vector<int> p(T+1);
	for(int i = 1 ; i < T + 1 ; i++)
		scanf("%d",&p[i]);

	vector<int> dp(T+1);
	for(int i = 1 ; i < T + 1 ; i++){
		for(int j = 1 ; j <= i ; j++){
			dp[i] = max(dp[i],dp[i-j] + p[j]);
		}
	}

	printf("%d\n",dp[T]);
	return 0;
}
*/
