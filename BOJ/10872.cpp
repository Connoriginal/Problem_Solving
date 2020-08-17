#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long ans = 1;

int main(void){
	scanf("%d",&N);
	for(int i = 1 ; i < N + 1 ; i++)
		ans *= i;
	printf("%llu\n",ans);
	
	return 0;
}