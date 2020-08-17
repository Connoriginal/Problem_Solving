#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int N;
int num[201];

int main(void){
	scanf("%d",&N);
	while(N--){
		int tmp;
		scanf("%d",&tmp);
		tmp += 100;
		num[tmp]++;
	}
	
	int v;
	scanf("%d",&v);
	printf("%d\n",num[v+100]);
	return 0;
}