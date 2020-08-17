#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 1001;

int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int N;
		char c;
		char string[MAX] = "";
		scanf("%d",&N);
		for(int i = 0 ; i < N ; i++){
			scanf(" %c",&c);
			char temp[MAX] = "";
			temp[0] = c;
			if(i == 0) strcat(string,temp);
			else{
				if(strcmp(string,temp) >= 0){
					strcat(temp,string);
					strcpy(string,temp);
				}
				else{
					strcat(string,temp);
				}
			}
		}
		printf("%s\n",string);
	}
	return 0;
}
//deque사용도 가능