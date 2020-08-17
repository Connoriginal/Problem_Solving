#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <stack>

using namespace std;

char list[100001];
stack<int> stk;
int ans = 0;

int main() {
	scanf("%s",list);
	int len = strlen(list);
	
	for(int i = 0 ; i < len ; i++){
		if(list[i] == '(')
			stk.push(i);
		else if(list[i] == ')'){
			ans += ((i - stk.top()) > 1) ? 1 : stk.size()-1; 
			stk.pop();
		}
	}
	
	printf("%d\n",ans);	
	return 0;
}