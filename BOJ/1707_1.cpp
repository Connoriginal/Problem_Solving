#include <iostream>
#include <cstdio> 
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> graph[20002];
int check[20002];

bool dfs(int node, int col){
	check[node] = col;
	for(int i = 0 ; i < graph[node].size() ; i++){
		int next = graph[node][i];
		if(check[next]==0){
			if(dfs(next,3-col) == false)
				return false;
		}
		else if(check[next] == col)
			return false;
	}
	return true;
}
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int N, E;
		scanf("%d %d",&N,&E);
		for(int i = 0 ; i < E ; i++){
			int u,v;
			scanf("%d %d",&u,&v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		
		for(int i = 1 ; i < N ; i++)
			sort(graph[i].begin(),graph[i].end());
		
		bool ok = true;
		for(int i = 1 ; i <= N ; i++){
			if(check[i] == 0){
				if(dfs(i,1) == false)
					ok = false;
			}
		}
		
		printf("%s\n", ok ? "YES" : "NO");
		
		for(int i = 1 ; i <= N ; i++){
			graph[i].clear(); check[i] = 0;
		}
	}
	
	return 0;
}