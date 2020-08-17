#include <cstdio> 
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

char str[80];
int score[80];

int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		int len = strlen(str);
		
		if(str[0] == 'O')
			score[0] = 1;
		else
			score[0] = 0;
		
		
		for(int i = 1 ; i < len ; i++){
			if(str[i] == 'O'){
				score[i] = score[i-1] + 1;
			}
			else{
				score[i] = 0;
			}
		}
		
		int ans = 0;
		for(int i = 0 ; i < len ; i++)
			ans += score[i];
		
		printf("%d\n",ans);
	}
	return 0;
}

