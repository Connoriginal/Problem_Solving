#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
const int INF = 5000;

int main(void){
	int N;
	scanf("%d",&N);
	
	int cnt = INF;
	
	for(int i = 0 ; 3 * i <= N ; i++){
		if((N - 3*i) % 5 == 0){
			int tmp = (N - 3*i) / 5;
			if(tmp + i < cnt){
				cnt = i + tmp;
			}
		}
	}
	
	if(cnt == INF){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",cnt);
	return 0;
}

