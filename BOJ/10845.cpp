#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <queue>

using namespace std;

int t;
char cmd[10];
queue<int> que;

int main(void) {
	scanf("%d",&t);
	while(t--){
		scanf("%s",cmd);
		if(!strcmp(cmd,"push")){
			int temp;
			scanf("%d",&temp);
			que.push(temp);
		}
		else if(!strcmp(cmd,"pop")){
			if(que.empty()){
				printf("%d\n",-1);
				continue;
			}
			printf("%d\n",que.front());
			que.pop();
		}
		else if(!strcmp(cmd,"size"))
			printf("%lu\n",que.size());
		else if(!strcmp(cmd,"empty")) 
			printf("%d\n",que.empty());
		else if(!strcmp(cmd,"front")){
			if(que.empty()){
				printf("%d\n",-1);
				continue;
			}
			printf("%d\n",que.front());
		}
		else if(!strcmp(cmd,"back")){
			if(que.empty()){
				printf("%d\n",-1);
				continue;
			}
			printf("%d\n",que.back());
		}
	}
	return 0;
}