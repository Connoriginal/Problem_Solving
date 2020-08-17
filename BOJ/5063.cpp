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
	int N;
	scanf("%d",&N);
	while(N--){
		int r,e,c;
		scanf("%d %d %d",&r,&e,&c);
		int ad = e - c;
		if(r > ad)
			printf("do not advertise\n");
		else if(r == ad)
			printf("does not matter\n");
		else
			printf("advertise\n");
	}
	return 0;
}

