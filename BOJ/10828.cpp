#include <iostream>
#include <cstdio> 
#include <stack>
#include <cstring>

using namespace std;

int t;
char order[100];
stack<int> stk;

int main(void){
	scanf("%d",&t);
	

	while(t--){
		scanf("%s",order);
		if(strcmp(order,"push")==0){
			int temp;
			scanf("%d",&temp);
			stk.push(temp);
		}
		else if(strcmp(order,"pop")==0){
			if(!stk.empty()){
				printf("%d\n",stk.top());
				stk.pop();
				continue;
			}
			printf("%d\n",-1);
		}
		else if(strcmp(order,"size")==0)
			printf("%lu\n",stk.size());
		
		else if(strcmp(order,"empty")==0){
			if(stk.empty())
				printf("%d\n",1);
			else 
				printf("%d\n",0);
		}
		
		else if(strcmp(order,"top")==0){
			if(stk.empty())
				printf("%d\n",-1);
			else
				printf("%d\n",stk.top());
		}
		
	}
}
