#include <cstdio> 
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> edge[51];
bool check[51];
int parent[51];
int N;

int main(void){
	scanf("%d",&N);
	int root;
	for(int i = 0 ; i < N ; i++){
		int par;
		scanf("%d",&par);
		parent[i] = par;
		if(par == -1){
			root = i;
			continue;
		}
		edge[par].push_back(i);
	}
	int del;
	scanf("%d",&del);
	
	int up = parent[del];
	for(int i = 0 ; i < edge[up].size() ; i++){
		if(edge[up][i] == del){
			edge[up].erase(edge[up].begin() + i);
			break;
		}
	}
	
	
	int cnt = 0;
	
	if(del == root){
		printf("%d\n",cnt);
		return 0;
	}
	queue<int> que;
	que.push(root);
	check[root] = true;
	while(!que.empty()){
		int node = que.front();
		que.pop();
		if(edge[node].size() > 0){
			for(int i = 0 ; i < edge[node].size() ; i++){
				int next = edge[node][i];
				if(check[next] == false){
					check[next] = true;
					que.push(next);
				}
			}
		}
		else{
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}

