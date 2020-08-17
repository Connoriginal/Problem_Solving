#include <cstdio> 
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
const int INF = 1000001;
vector<pair<int,int>> edge[10001],edge_r[10001];
int N, M, X;
int dist[1001][2]; //1이 rev

void dijkstra(int start,int type){
	priority_queue<pair<int,int>> que;
	que.push(make_pair(0,start));
	if(type == 0){
		while(!que.empty()){
			int node = que.top().second;
			int len = que.top().first;
			que.pop();
			if(dist[node][type] < len) continue;

			for(int i = 0 ; i < edge[node].size() ; i++){
				int next = edge[node][i].first;
				int next_len = len + edge[node][i].second;
				if(dist[next][type] > next_len){
					dist[next][type] = next_len;
					que.push(make_pair(next_len,next));
				}
			}
		}
	}
	else{
		while(!que.empty()){
			int node = que.top().second;
			int len = que.top().first;
			que.pop();
			if(dist[node][type] < len) continue;

			for(int i = 0 ; i < edge_r[node].size() ; i++){
				int next = edge_r[node][i].first;
				int next_len = len + edge_r[node][i].second;
				if(dist[next][type] > next_len){
					dist[next][type] = next_len;
					que.push(make_pair(next_len,next));
				}
			}
		}
	}
	
}

int main(void){

	scanf("%d %d %d",&N,&M,&X);
	for(int i = 0 ; i < M ; i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		edge[u].push_back(make_pair(v,w));
		edge_r[v].push_back(make_pair(u,w));
	}
	
	for(int i = 1 ; i <= N ; i++){
		dist[i][0] = INF; dist[i][1] = INF;
	}
	dist[X][0] = 0; dist[X][1] = 0;
	dijkstra(X,0); dijkstra(X,1);
	
	int ans = 0;
	for(int i = 1 ; i <= N ; i++){
		if(i == X) continue;
		int len = dist[i][0] + dist[i][1];
		ans = max(len,ans);
	}
	printf("%d\n",ans);
	return 0;
}

