#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

stack<int> mel[7];
int N,P;

int main(void){
	scanf("%d %d",&N,&P);
	int cnt = 0;
	for(int i = 0 ; i < N ; i++){
		int line, flat;
		scanf("%d %d",&line,&flat);
		while(!mel[line].empty()){
			if(mel[line].top() > flat){
				cnt++;
				mel[line].pop();
			}
			else if(mel[line].top() == flat){
				cnt--;
				mel[line].pop();
				break;
			}
			else{
				break;
			}
		}
		cnt++;
		mel[line].push(flat);
		
	}
	
	printf("%d\n",cnt);
	return 0;
}