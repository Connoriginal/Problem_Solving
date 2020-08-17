#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dist[200000];
bool check[200000];
int N,K;

int main() {
	scanf("%d %d",&N,&K);
	int x = N;
	queue<int> que;

	que.push(x);
	check[x] = true;
	dist[x] = 0;

	while(!que.empty()){
		x = que.front();
		que.pop();

		if(check[K] == true) break;

		if(!check[x-1] && x-1 >= 0){
			que.push(x-1);
			check[x-1] = true;
			dist[x-1] = dist[x] + 1;
		}

		if(!check[x+1] && x+1 <= 200000){
			que.push(x+1);
			check[x+1] = true;
			dist[x+1] = dist[x] + 1;
		}

		if(!check[2*x] && 2*x <= 200000){
			que.push(2*x);
			check[2*x] = true;
			dist[2*x] = dist[x] + 1;
		}
	}

	printf("%d\n",dist[K]);
    return 0;
}
/* 더 나은 version
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int sec[100001];
int cal[3] = {1,-1,2};

int main() {
  int n,k;
  scanf("%d %d",&n,&k);

  memset(sec,-1,sizeof(sec));
  queue<int> q;
  q.push(n);sec[n] = 0;
  while(!q.empty()){
    int node = q.front(); q.pop();
    for(int i = 0 ; i < 3 ; i++){
      int next;
      if(i == 2) next = cal[i]*node;
      else next = node + cal[i];

      if(0 <= next && next <= 100000){
        if(sec[next] == -1 || sec[next] > sec[node] + 1){
          q.push(next);
          sec[next] = sec[node] + 1;
        }
      }
    }
  }
  printf("%d\n",sec[k]);
  return 0;
}

*/
