#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

bool check[10000];
int cnt[10000];
bool prime[10000];//false가 소수

int change(int a, int idx, int to){
	if(idx == 0 && to == 0) return -1;
	string str = to_string(a);
	str[idx] = to + '0';
	return stoi(str);
}

int main() {
	for(int i = 2 ; i*i < 10000 ; i++){
		if(prime[i] == false){
			for(int j = i*i; j < 10000 ; j+=i){
				prime[j] = true;
			}
		}
	}

	int t;
	scanf("%d",&t);
	while(t--){
		memset(check,false,sizeof(check));
		memset(cnt,0,sizeof(cnt));

		int a,b;
		scanf("%d %d",&a,&b);

		queue<int> que;
		que.push(a);
		check[a] = true;

		while(!que.empty()){
			int now = que.front();
			que.pop();

			if(now == b) break;


			for(int i = 0 ; i < 4 ; i++){
				for(int j = 0 ; j < 10 ; j++){
					int next = change(now,i,j);
					if(next != -1){
						if(!prime[next] && !check[next]){
							que.push(next);
							check[next] = true;
							cnt[next] = cnt[now] + 1;
						}
					}
				}
			}
		}

		printf("%d\n",cnt[b]);
	}
    return 0;
}
/* 더나은 version
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

bool prime[10000];
int ans[10000];

int pow(int a){
  int ans = 1;
  for(int i = 0 ; i < a ; i++){
    ans *= 10;
  }
  return ans;
}

int change(int cur, int x, int y){
  if(x == 4 && y == 0) return -1;
  int div = pow(x-1);
  int top = cur / (div*10);
  int bot = cur % div;
  int ans = top*(div*10) + y*div + bot;
  if(!prime[ans]){
    return ans;
  }
  return -1;
}

int main() {
  for(int i = 2 ; i < 10000 ; i++){
    if(!prime[i]){
      for(int j = i * i ; j < 10000 ; j+=i){
        prime[j] = true;
      }
    }
  }

  int t;
  scanf("%d",&t);

  while(t--){
    int start, end;
    scanf("%d %d",&start,&end);

    memset(ans,-1,sizeof(ans));

    queue<int> q;
    q.push(start);ans[start] = 0;

    while(!q.empty()){
      int now = q.front();q.pop();
      for(int i = 1 ; i <= 4 ; i++){
        for(int j = 0 ; j < 10 ; j++){
          int next = change(now,i,j);
          if(next != -1 && (ans[next] == -1 || ans[next] > ans[now] + 1)){
            ans[next] = ans[now] + 1;
            q.push(next);
          }
        }
      }
    }

    if(ans[end] == -1){
      printf("Impossible");
    }
    else{
      printf("%d\n",ans[end]);
    }
  }
  return 0;
}
*/
