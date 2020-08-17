#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <stack>

using namespace std;

char list[100005];
int N;
stack<char> stkleft;
stack<char> stkright;

int main(void) {
	scanf("%s",list);
	int len = strlen(list);
	for(int i = 0 ; i < len ; i++)
		stkleft.push(list[i]);

	scanf("%d",&N);
	
	while(N--){
		char tmp;
		scanf(" %c",&tmp);
		
		if(tmp == 'L'){
			if(!stkleft.empty()){
				stkright.push(stkleft.top());
				stkleft.pop();
			}
		}
		else if(tmp == 'D'){
			if(!stkright.empty()){
				stkleft.push(stkright.top());
				stkright.pop();			
			}

		}
		else if (tmp == 'B'){
			if(!stkleft.empty())
				stkleft.pop();
		}	
		else if(tmp == 'P'){
			char val;
			scanf(" %c",&val);
			stkleft.push(val);
		}
	}
	
	while(!stkleft.empty()){
		stkright.push(stkleft.top());
		stkleft.pop();
	}
	
	while(!stkright.empty()){
		putchar(stkright.top());
		stkright.pop();
	}
	
	putchar('\n');
	
	return 0;
}