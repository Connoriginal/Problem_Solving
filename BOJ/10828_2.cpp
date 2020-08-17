#include <iostream> 
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

int t;
string cmd;
stack<int> stk;

int main(void){
	scanf("%d",&t);
	
	while(t--){	
		cin >> cmd;
		if(cmd == "push"){
			int tmp;
			scanf("%d",&tmp);
			stk.push(tmp);
		}
		else if(cmd == "pop"){
			if(stk.empty()){
				printf("%d\n",-1);
				continue;
			}
			printf("%d\n",stk.top());
			stk.pop();
		}
		else if(cmd == "size")
			printf("%lu\n",stk.size());
		else if(cmd == "empty"){
			if(stk.empty()){
				printf("%d\n",1);
				continue;
			}
			printf("%d\n",0);
		}
		else if(cmd == "top"){
			if(stk.empty()){
				printf("%d\n",-1);
				continue;
			}
			printf("%d\n",stk.top());
		}
	}
	return 0;
}
