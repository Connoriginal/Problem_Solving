#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int num[10];

int main(void){
	int inp;
	scanf("%d",&inp);
	while(inp>0){
		if(inp%10 == 9)
			num[6]++;
		num[inp%10]++;
		inp /= 10;
	}
	
	if(num[6]%2==0)
		num[6] = num[6] / 2;
	else
		num[6] = num[6] / 2 + 1;
	
	int ans = 1;
	for(int i = 0 ; i < 9 ; i++){
		ans = max(ans,num[i]);
	}
	
	printf("%d\n",ans);
	
	return 0;
}