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

int cnt = 0;

void solve(int n, int m){
	if(n == 1 && m == 1)
		return;
	

	if(n > m){
		solve(n/2,m);
		solve(n - n/2,m);
		cnt++;
	}
	else{
		solve(n,m/2);
		solve(n,m - m/2);
		cnt++;
	}
	return;
}

int main(void){
	int N,M;
	scanf("%d %d",&N,&M);
	solve(N,M);
	printf("%d\n",cnt);
	return 0;
}

