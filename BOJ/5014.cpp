#include <iostream>
#include <queue>

using namespace std;

int dist[1000001];
bool check[1000001];


int main() {
	int height,now,goal,up,down;
	scanf("%d %d %d %d %d",&height,&now,&goal,&up,&down);
	queue<int> que;
	dist[now] = 0;
	check[now] = true;
	que.push(now);
	while(!que.empty()){
		int node = que.front(); que.pop();

		if(node == goal) break;

		if(node + up <= height){
			int next = node + up;
			if(!check[next]){
				dist[next] = dist[node] + 1;
				check[next] = true;
				que.push(next);
			}
		}

		if(node - down >= 1){
			int next = node - down;
			if(!check[next]){
				dist[next] = dist[node] + 1;
				check[next] = true;
				que.push(next);
			}
		}
	}

	if(check[goal] == false)
		printf("use the stairs\n");
	else
		printf("%d\n",dist[goal]);

    return 0;
}

/*version 2
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int cnt[1000001];

bool check(int next, int now){
  return (0 <= next && next <= 1000000) && (cnt[next] == -1 || cnt[next] > cnt[now] + 1);
}
int main() {
  int f,s,g,u,d;
  scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);

  memset(cnt,-1,sizeof(cnt));

  queue<int> q;
  q.push(s);cnt[s] = 0;
  while(!q.empty()){
    int now = q.front(); q.pop();
    int next = now + u;
    if(check(next,now)){
      cnt[next] = cnt[now]+1;
      q.push(next);
    }

    next = now - d;
    if(check(next,now)){
      cnt[next] = cnt[now] + 1;
      q.push(next);
    }
  }

  if(cnt[g] == -1) printf("use the stairs\n");
  else printf("%d\n",cnt[g]);
  return 0;
}
*/
