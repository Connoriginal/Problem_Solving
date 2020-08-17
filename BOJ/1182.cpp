#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N,S;
int arr[21];
int ans = 0;

void solve(int cnt, int i){
	if(i == N){
		if(cnt == S)
			ans++;
		return;
	}

	solve(cnt,i+1);
	solve(cnt+arr[i],i+1);
	return;
}


int main() {
	scanf("%d %d",&N,&S);
	for(int i = 0 ; i < N ; i++)
		scanf("%d",&arr[i]);

	solve(0,0);
	if(S==0) ans--;
	printf("%d\n",ans);
    return 0;
}
/* 비트마스크
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int a[21];
int n,s;

int main(void){
  scanf("%d %d",&n,&s);

  for(int i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }

  int ans = 0;

  for(int i = 1 ; i < (1<<n) ; i++){
    int sum = 0;
    for(int j = 1, k = 0; j <= i ; j*=2, k++){
      if(i & j) sum += a[k];
    }
    if(sum == s) ans++;
  }

  printf("%d\n",ans);
  return 0;
}
*/
