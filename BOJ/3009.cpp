#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int xarr[3];
int yarr[3];

int main(void){
	for(int i = 0 ; i < 3 ; i++){
		scanf("%d %d",&xarr[i],&yarr[i]);
	}
	
	int x = xarr[0], y = yarr[0];
	int xidx = 0, yidx = 0;
	for(int i = 1 ; i < 3 ; i++){
		if(x == xarr[i])
			xidx = 3 - i;
		if(y == yarr[i])
			yidx = 3 - i;
	}
	
	printf("%d %d\n",xarr[xidx],yarr[yidx]);
	return 0;
}