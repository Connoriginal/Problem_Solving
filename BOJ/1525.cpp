#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main() {
	int start = 0;
	
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			int tmp;
			scanf("%d",&tmp);
			if(tmp == 0) tmp = 9;
			start = 10*start + tmp;
		}
	}
	
	queue<int> que;
	map<int,int> dist;
	que.push(start);
	dist[start] = 0;
	
	while(!que.empty()){
		int now_num = que.front();
		string now = to_string(now_num);
		que.pop();
		
		int z = now.find('9');
		int x = z/3;
		int y = z%3;
		
		for(int k = 0 ; k < 4 ; k++){
			int nx = x + dx[k]; int ny = y + dy[k];
			if(0 <= nx && nx < 3 && 0 <= ny && ny < 3){
				string next = now;
				swap(next[x*3+y],next[nx*3+ny]);
				int next_num = stoi(next);
				if(dist.count(next_num) == 0){
					dist[next_num] = dist[now_num] + 1;
					que.push(next_num);
				}
			}
		}
	}
	
	if(dist.count(123456789) == 0)
		printf("-1\n");
	else{
		printf("%d\n",dist[123456789]);
	}
    return 0;
}