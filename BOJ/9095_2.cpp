#include <iostream>
#include <cstdio>

using namespace std;


int solve(int cnt, int sum , int goal){
	int now = 0;

	if(cnt > 10) return 0;
	if(sum > goal) return 0;
	if(sum == goal) return 1;

	for(int i = 1 ; i <= 3 ; i++){
		now += solve(cnt+1,sum+i,goal);
	}
	return now;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n",solve(0,0,n));
	}
    return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

int solve(int temp){
  if(temp < 0) return 0;
  else if(temp < 2) return 1;
  int ans = 0;
  for(int i = 1 ; i <= 3 ; i++){
    ans += solve(temp-i);
  }
  return ans;
}

int main() {
  int t;
  scanf("%d",&t);
  while(t--){
    int temp;
    scanf("%d",&temp);
    printf("%d\n",solve(temp));
  }
  return 0;
}
*/
