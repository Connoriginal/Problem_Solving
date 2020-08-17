#include <cstdio>
#include <iostream>

using namespace std;

// using math

int N;

int main(void){
	scanf("%d",&N);
	int ans = 0;
	int num = 1;
	while(true){
		long long tmp = num * (num+1) / 2;
		if(tmp > N) break;
		if((N-tmp) % num == 0) ans++;
		num++;
	}
	printf("%d\n",ans);
	return 0;
}

/* using two pointer
#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  int n;
  scanf("%d",&n);

  int sp = 1, ep = 1, sum = 1, cnt = 0;

  while(sp < n){
    if(sum >= n){
      sum -= sp++;
    }
    else{
      sum += ++ep;
    }
    if(sum == n) cnt++;
  }

  printf("%d\n",cnt);
  return 0;
}
*/
