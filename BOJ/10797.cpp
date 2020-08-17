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


int main(void){
	int day;
	int cnt = 0;
	scanf("%d",&day);
	for(int i = 0 ; i < 5 ; i++){
		int tmp;
		scanf("%d",&tmp);
		if(tmp == day) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}

