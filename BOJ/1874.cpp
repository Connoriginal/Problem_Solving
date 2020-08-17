#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <stack>

using namespace std;

int list[100010];
int sp = 0,lp = 0,n;
stack<int> stk;
char ans[200010];


int main(void) {
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d",&list[i]);
	
	for(int i = 1 ; i < n + 1 ; i++){
		stk.push(i);
		ans[sp++] = '+';
		while(list[lp] == stk.top()){
			lp++;
			stk.pop();
			ans[sp++] = '-';
			if(stk.empty()) break;
		}
	}

	ans[sp] = '\0';
	
	if(stk.empty())
		for(int i = 0 ; i < sp ; i++)
			printf("%c\n",ans[i]);
	else
		printf("%s\n","NO");
	
	return 0;
}