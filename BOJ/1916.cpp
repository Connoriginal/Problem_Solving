#include <cstdio> 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int MAX_N = 1001;
const int INF = 1000000000;
typedef pair<int,int> P;

int dist[MAX_N];
bool visit[MAX_N];
vector<P> edge[MAX_N];
int N,M;

int main(void){
	scanf("%d %d",&N,&M);
	
	for(int i = 0 ; i < M ; i++){
		int u, v, w;
		scanf("%d %d %d",&u,&v,&w);
		edge[u].push_back(P(v,w));
	}
	
	int start,end;
	scanf("%d %d",&start,&end);
	
	fill(dist,dist+N+1,INF);
	
	priority_queue<P,vector<P>,greater<P>> PQ;
	PQ.push(P(0,start));
	dist[start] = 0;
	
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(visit[curr] && !PQ.empty());
		
		visit[curr] = true;
		
		for(auto &p : edge[curr]){
			int next = p.first;
			int len = p.second;
			if(dist[next] > dist[curr] + len){
				dist[next] = dist[curr] + len;
				PQ.push(P(dist[next],next));
			}
		}
	}
	
	printf("%d\n",dist[end]);
	return 0;
}