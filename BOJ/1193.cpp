#include <cstdio> 
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int main(void){
	int N;
	scanf("%d",&N);
	int sum = 1;
	int add = 2;
	int level = 1;
	while(sum < N){
		sum += add;
		add++;
		level++;
	}
	
	int fir,sec;
	
	if(level % 2 == 0){
		fir = level;
		sec = 1;
	}
	else{
		fir = 1;
		sec = level;
	}
	
	if(sum > N){
		int tmp = sum - N;
		while(tmp >0){
			if(level % 2 == 0){
				fir--;sec++;
			}
			else{
				fir++;sec--;
			}
			tmp--;
		}
	}
	
	printf("%d/%d\n",fir,sec);
	return 0;
}

