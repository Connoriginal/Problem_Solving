#include <cstdio> 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int MAX_V = 20001;
const int INF = 100000000;
typedef pair<int,int> P;
int dist[MAX_V];
bool visit[MAX_V];
vector<pair<int,int>> edge[300001];
int V, E, k;

int main(void){
	scanf("%d %d %d",&V,&E,&k);
	for(int i = 0 ; i < E ; i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		edge[u].push_back(make_pair(v,w));
	}
	
	fill(dist,dist + MAX_V,INF);
	
	priority_queue<P,vector<P>,greater<P>> PQ;
	dist[k] = 0;
	PQ.push(P(0,k));
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(visit[curr] && !PQ.empty());
		
		if(visit[curr]) break;
		
		visit[curr] = true;
		
		for(auto &x : edge[curr]){
			int next = x.first;
			int len = x.second;
			if(dist[next] > dist[curr] + len){
				dist[next] = dist[curr] + len;
				PQ.push(P(dist[next],next));
			}
		}
	}
	
	for(int i = 1; i <= V ; i++){
		if(dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n",dist[i]);
	}
	return 0;
}