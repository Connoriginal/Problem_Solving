#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

long long p[105] = {0,1,1,1,2,2,3,4,5,7,9};

int main(void){
	int T;
	scanf("%d",&T);

	while(T--){
		int temp;
		scanf("%d",&temp);
		for(int i = 11 ; i < temp + 1 ; i++){
			if(p[i] > 0) continue;
			p[i] = p[i-1] + p[i-5];
		}
		printf("%llu\n",p[temp]);
	}
	return 0;
}

/* Top-Down
#include <iostream>
#include <cstdio>

using namespace std;

long long d[101];

long long dp(int x){
  if(x == 1 || x == 2 || x == 3){
    return 1;
  }
  if(d[x] > 0) return d[x];

  return d[x] = dp(x-2) + dp(x-3);
}
int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);

    printf("%lld\n",dp(n));
  }
  return 0;
}
*/
