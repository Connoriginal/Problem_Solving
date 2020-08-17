#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool prime(int n){
	if(n < 2)
		return false;
	for(int i = 2 ; i*i <= n ; i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

int ans = 0;

int main(void){
	int N;
	scanf("%d",&N);
	while(N--){
		int tmp;
		scanf("%d",&tmp);
		ans += prime(tmp);
	}

	printf("%d\n",ans);

	return 0;
}
/*
#include <iostream>
#include <cstdio>

using namespace std;

bool prime[1001]; // false가 소수

int main(void){
  prime[1] = true;

  for(int i = 2 ; i <= 1000 ; i++){
    if(prime[i] == true) continue;
    for(int j = i*i ; j <= 1000 ; j += i){
      prime[j] = true;
    }
  }

  int n;
  scanf("%d",&n);

  int ans = 0;

  for(int i = 0 ; i < n ; i++){
    int tmp;
    scanf("%d",&tmp);
    if(!prime[tmp]) ans++;
  }

  printf("%d\n",ans);
  return 0;
}
*/
