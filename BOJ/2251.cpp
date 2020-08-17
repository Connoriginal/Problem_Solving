#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int from[] = {0,0,1,1,2,2};
int to[] = {1,2,0,2,0,1};
int arr[3];
bool ans[201];
bool check[201][201];

int main() {
	for(int i = 0 ; i < 3 ; i++)
		scanf("%d",&arr[i]);

	queue<pair<int,int>> que;
	
	que.push(make_pair(0,0));
	check[0][0] = true;
	ans[arr[2]] = true;
	
	while(!que.empty()){
		int curr[3];
		curr[0] = que.front().first; curr[1] = que.front().second;
		curr[2] = arr[2] - curr[0] - curr[1];
		que.pop();
		
		for(int k = 0 ; k < 6 ; k++){
			int next[] = {curr[0],curr[1],curr[2]};
			next[to[k]] += next[from[k]];
			next[from[k]] = 0;
			if(next[to[k]] > arr[to[k]]){
				next[from[k]] = next[to[k]] - arr[to[k]];
				next[to[k]] = arr[to[k]];
			}
			
			if(!check[next[0]][next[1]]){
				check[next[0]][next[1]] = true;
				que.push(make_pair(next[0],next[1]));
				if(next[0] == 0) ans[next[2]] = true;
			}
			
		}
		
	}
	
	for(int i = 0 ; i <= arr[2] ; i++){
		if(ans[i])
			printf("%d ",i);
	}
	printf("\n");
    return 0;
}
