#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main(void){
	int ans = 0;
	int tmp;
	for(int i = 0 ; i < 5 ; i++){
		scanf("%d",&tmp);
		ans += tmp * tmp;
	}
	printf("%d\n",ans%10);
	return 0;
}