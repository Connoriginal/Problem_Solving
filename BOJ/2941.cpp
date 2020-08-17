#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

char str[101];

int main(void){
	int cnt = 0;
	scanf("%s",str);
	int len = strlen(str);
	for(int i = 0 ; i < len ; i++){
		char tmp = str[i];
		if(tmp == 'c'){
			if(i + 1 < len && str[i+1] == '=' || str[i+1] == '-'){
				i++;
			}
		}
		
		if(tmp == 'd'){
			if(i+1 < len && str[i+1] == '-')
				i++;
			else if(i+2 < len && str[i+1] == 'z' && str[i+2] == '=')
				i+=2;
		}
		
		if(tmp == 'l'){
			if(i+1 < len && str[i+1] == 'j')
				i++;
		}
		
		if(tmp == 'n'){
			if(i+1 < len && str[i+1] == 'j')
				i++;
		}
		
		if(tmp == 's'){
			if(i+1 < len && str[i+1] == '=')
				i++;
		}
		
		if(tmp == 'z'){
			if(i+1 < len && str[i+1] == '=')
				i++;
		}
		cnt++;
	}
	
	printf("%d\n",cnt);
	return 0;
}