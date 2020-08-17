#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[91][2];
int main(void){
	int N;
	scanf("%d",&N);
	dp[1][0] = 0; dp[1][1] = 1;
	for(int i = 2 ; i < N + 1 ; i++){
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}

	long long ans = dp[N][0] + dp[N][1];

	printf("%llu\n",ans);
	return 0;
}
