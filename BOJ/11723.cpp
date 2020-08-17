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

char str[100];
int t;

int main(void){
	scanf("%d",&t);
	int S = 0;
	while(t--){
		scanf("%s",str);
		int x;
		if(!strcmp(str,"add")){
			scanf("%d",&x);
			S = S|(1 << x);
		}
		else if(!strcmp(str,"remove")){
			scanf("%d",&x);
			S = S & (~(1 << x));
		}
		else if(!strcmp(str,"check")){
			scanf("%d",&x);
			if(S&(1 << x))
				puts("1");
			else
				puts("0");
		}
		else if(!strcmp(str,"toggle")){
			scanf("%d",&x);
			S = S ^ (1<<x);
		}
		else if(!strcmp(str,"all")){
			S = (1<<21)-1;
		}
		else if(!strcmp(str,"empty")){
			S = 0;
		}
		
	}
	return 0;
}

