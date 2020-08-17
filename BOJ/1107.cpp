#include <cstdio>
#include <iostream>

using namespace std;

bool broke[10];

int solve(int x){
	int len = 0;
	if(x==0){
		return broke[0] ? 0 : 1;
	}
	while(x > 0){
		int tmp = x % 10;
		if(broke[tmp]) return 0;
		x /= 10;
		len++;
	}
	return len;
}

int N;

int main(void){
	scanf("%d",&N);
	int m;
	scanf("%d",&m);
	while(m--){
		int tmp;
		scanf("%d",&tmp);
		broke[tmp] = true;
	}

	int cur_channel = 100;
	int ans = (N > cur_channel) ? N - cur_channel : cur_channel - N;

	for(int i = 0 ; i <= 1000000 ; i++){
		int len = solve(i);
		if(len > 0){
			int check = (N > i) ? N - i : i - N;
			if(check + len < ans)
				ans = check + len;
		}
	}

	printf("%d\n",ans);
	return 0;
}
/* 더 빠른 version
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

bool broken[10];

int check(int i, int n){
  if(i == 0) return broken[0] ? 0 : 1 + abs(i-n);
  int x = i;
  int ans = 0;
  while(x>0){
    if(broken[x%10]){
      return 0;
    }
    ans++;
    x /= 10;
  }
  return ans + abs(i-n);
}

int main() {
  string str;
  cin >> str;
  int n = stoi(str);

  int broke_num;
  scanf("%d",&broke_num);
  while(broke_num--){
    int temp;
    scanf("%d",&temp);
    broken[temp] = true;
  }


  int ans = abs(n-100);

  if(ans <= str.size()){
    printf("%d\n",ans);
    return 0;
  }

  for(int i = n ; i >= 0 ; i--){
    int temp = check(i,n);
    if(temp > 0){
      ans = min(temp,ans);
      break;
    }
  }

  for(int i = n ; i <= 1000000 ; i++){
    int temp = check(i,n);
    if(temp >0){
      ans = min(temp,ans);
      break;
    }
  }

  printf("%d\n",ans);
  return 0;
}
*/
