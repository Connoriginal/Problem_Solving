#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <deque>

using namespace std;

deque<int> dq;
int N;
char cmd[10];

int main(void) {
	scanf("%d",&N);
	while(N--){
		scanf("%s",cmd);
		if(!strcmp(cmd,"push_front")){
			int tmp;
			scanf("%d",&tmp);
			dq.push_front(tmp);
		}
		else if(!strcmp(cmd,"push_back")){
			int tmp;
			scanf("%d",&tmp);
			dq.push_back(tmp);
		}
		else if(!strcmp(cmd,"pop_front")){
			if(dq.empty()){
				printf("%d\n",-1);
				continue;
			}
			printf("%d\n",dq.front());
			dq.pop_front();
		}
		else if(!strcmp(cmd,"pop_back")){
			if(dq.empty()){
				printf("%d\n",-1);
				continue;
			}
			printf("%d\n",dq.back());
			dq.pop_back();
		}
		else if(!strcmp(cmd,"size"))
			printf("%lu\n",dq.size());
		else if(!strcmp(cmd,"empty"))
			printf("%d\n",dq.empty());
		else if(!strcmp(cmd,"front")){
			if(dq.empty()){
				printf("%d\n",-1);
				continue;
			}
			printf("%d\n",dq.front());
		}
		else if(!strcmp(cmd,"back")){
			if(dq.empty()){
				printf("%d\n",-1);
				continue;
			}
			printf("%d\n",dq.back());
		}
	}
	return 0;
}