#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

char order[10000];
int from[10000];
int cnt[10000];
bool check[10000];

int d(int n){
	if(2*n >= 10000) return (2*n) % 10000;
	return 2*n;
}

int s(int n){
	if(n==0) return 9999;
	return n-1;
}

int l(int n){
	return (n % 1000) * 10 + n/1000;
}

int r(int n){
	return (n%10) * 1000 + n / 10;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		memset(order,0,sizeof(order));
		memset(from,0,sizeof(from));
		memset(cnt,0,sizeof(cnt));
		memset(check,false,sizeof(check));

		int a,b;
		scanf("%d %d",&a,&b);
		queue<int> que;
		que.push(a);
		check[a] = true;
		while(!que.empty()){
			int now = que.front();
			que.pop();

			if(now == b) break;

			int next = d(now);
			if(!check[next]){
				que.push(next);
				check[next] = true;
				cnt[next] = cnt[now] + 1;
				from[next] = now;
				order[next] = 'D';
			}

			next = s(now);
			if(!check[next]){
				que.push(next);
				check[next] = true;
				cnt[next] = cnt[now] + 1;
				from[next] = now;
				order[next] = 'S';
			}

			next = l(now);
			if(!check[next]){
				que.push(next);
				check[next] = true;
				cnt[next] = cnt[now] + 1;
				from[next] = now;
				order[next] = 'L';
			}

			next = r(now);
			if(!check[next]){
				que.push(next);
				check[next] = true;
				cnt[next] = cnt[now] + 1;
				from[next] = now;
				order[next] = 'R';
			}

		}

		string ans = "";
		while(a!=b){
			ans += order[b];
			b = from[b];
		}

		reverse(ans.begin(),ans.end());
		cout << ans << '\n';
	}
    return 0;
}

/* 시간 더 걸리지만 코드는 간결한 방법
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int num[10000];
vector<string> ans(10000);

int d(int x){
  int ans = 2*x;
  if(ans > 9999) ans %= 10000;
  return ans;
}

int s(int x){
  if(x == 0) return 9999;
  return x-1;
}

int l(int x){
  int a = x / 1000;
  return (x%1000) * 10 + a;
}

int r(int x){
  int a = x % 10;
  int b = x / 10;
  return a*1000 + b;
}

bool check(int next,int now){
  return num[next] == -1 || num[next] > num[now] + 1;
}


int main() {
  int t;
  scanf("%d",&t);
  while(t--){
    int start, end;
    scanf("%d %d",&start,&end);

    memset(num,-1,sizeof(num));

    queue<int> q;
    q.push(start);num[start] = 0; ans[start] = "";
    while(!q.empty()){
      int now = q.front(); q.pop();
      for(int i = 0 ; i < 4 ; i++){
        int next;

        next = d(now);
        if(check(next,now)){
          q.push(next);
          num[next] = num[now] + 1;
          ans[next] = ans[now] + "D";
        }

        next = s(now);
        if(check(next,now)){
          q.push(next);
          num[next] = num[now]+1;
          ans[next] = ans[now] + "S";
        }

        next = l(now);
        if(check(next,now)){
          q.push(next);
          num[next] = num[now]+1;
          ans[next] = ans[now] + "L";
        }

        next = r(now);
        if(check(next,now)){
          q.push(next);
          num[next] = num[now] + 1;
          ans[next] = ans[now] + "R";
        }
      }
    }

    cout << ans[end] << '\n';
  }
  return 0;
}
*/
