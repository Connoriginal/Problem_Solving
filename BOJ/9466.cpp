#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;

int check[100001];
int graph[100001];
int step[100001];

int dfs(int node, int cnt, int stp){
	check[node] = cnt;
	step[node] = stp;
	int next = graph[node];
	if(check[next] == 0){
		return dfs(next,++cnt,stp);
	}
	else{
		if(step[next] != stp)
			return 0;
		return cnt - check[next] + 1;
	}
}
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int n; int ans = 0;
		scanf("%d",&n);
		for(int i = 1 ; i <=n ; i++){
			scanf("%d",&graph[i]);
			check[i] = 0;
			step[i] = 0;
		}

		for(int i = 1 ; i <= n ; i++){
			if(check[i] == 0){
				ans += dfs(i,1,i);
			}
		}

		printf("%d\n",n - ans);
	}
	return 0;
}

/* 바로 정답 구한 케이스 시간50ms 줄임 코드는 70b늘어남
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int check[100001];
int check_num[100001];
int edge[100001];

int dfs(int x, int cnt, int c){
  check[x] = c;
  check_num[x] = cnt;
  int next = edge[x];
  if(check[next] == 0){
    return dfs(next,cnt+1,c);
  }
  else if(check[next] == c){
    return check_num[next]-1;
  }
  else{
    return cnt;
  }
}

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    memset(check,0,sizeof(check));
    memset(edge,0,sizeof(edge));

    int v;
    scanf("%d",&v);

    for(int i = 1 ; i <= v ; i++){
      scanf("%d",&edge[i]);
    }

    int ans = 0;
    for(int i = 1; i <= v ; i++){
      if(check[i] == 0){
        ans += dfs(i,1,i);
      }
    }

    printf("%d\n",ans);
  }
  return 0;
}
*/
