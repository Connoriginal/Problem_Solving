#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 100010;
bool check[MAX];
int parent[MAX];
vector<int> vec[MAX];
int depth[MAX];
int N;

int main(void){
	scanf("%d",&N);
	for(int i = 0 ; i < N-1 ; i++){
		int u,v;
		scanf("%d %d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	depth[1] = 0; parent[1] = 0; check[1] = true;

	queue<int> que;
	que.push(1);
	while(!que.empty()){
		int tmp = que.front();
		que.pop();
		for(int x : vec[tmp]){
			if(!check[x]){
				que.push(x);
				check[x] = true;
				parent[x] = tmp;
				depth[x] = depth[tmp] + 1;
			}
		}
	}

	for(int i = 2 ; i <= N ; i++)
		printf("%d\n",parent[i]);
	return 0;
}

/* dfs
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;

int parent[100001];
vector<int> edge[100001];
bool check[100001];

void dfs(int x){
  check[x] = true;
  for(int i = 0 ; i < edge[x].size() ; i++){
    int y = edge[x][i];
    if(!check[y]){
      parent[y] = x;
      dfs(y);
    }
  }
}

int main(void){
  int v;
  scanf("%d",&v);

  for(int i = 1 ; i < v ; i++){
    int u,v;
    scanf("%d %d",&u,&v);
    edge[u].push_back(v);edge[v].push_back(u);
  }

  dfs(1);

  for(int i = 2 ; i <= v ; i++){
    printf("%d\n",parent[i]);
  }
  return 0;
}
*/
