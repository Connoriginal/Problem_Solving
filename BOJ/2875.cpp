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

int N,M,K;
int main(void){
	scanf("%d %d %d",&N,&M,&K);
	int ans = 0;
	while(N + M >= K + 3 && N>=2 && M>=1){
		N -= 2;
		M--;
		ans++;
	}
	printf("%d\n",ans);
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
  int n,m,k;
  scanf("%d %d %d",&n,&m,&k);

  int team = (n/2 > m) ? m : n/2;
  k -= (n - 2*team) + (m - team);
  n = 2*team;
  m = team;

  while(k > 0 && n > 0 && m >0){
    team--;
    n -= 2;
    m -= 1;
    k -= 3;
  }

  printf("%d\n",team);
  return 0;
}
*/
