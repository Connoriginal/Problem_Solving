#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int T,cmd;
int dp[12];

int main(void){
	scanf("%d",&T);
	dp[1] = 1;dp[2] = 2; dp[3] = 4;
	while(T--){
		scanf("%d",&cmd);
		for(int i = 4 ; i < cmd + 1 ; i++)
			dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		printf("%d\n",dp[cmd]);
	}
	return 0;
}

/* Top-down
#include <iostream>
#include <cstdio>

using namespace std;

int d[12];

int dp(int x){
  if(d[x] > 0) return d[x];
  d[x] = dp(x-1) + dp(x-2) + dp(x-3);
  return d[x];
}

int main(void){
  d[1] = 1; d[2] = 2; d[3] = 4;
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);
    printf("%d\n",dp(n));
  }
  return 0;
}
*/
