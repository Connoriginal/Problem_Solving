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
int position[100001];
int inorder[100001];
int postorder[100001];
int N;

void solve(int is, int ie, int ps, int pe){
	if(is > ie || ps > pe) return;
	printf("%d ",postorder[pe]);
	int ir = position[postorder[pe]];
	int l = ir - is -1;
	solve(is,ir-1,ps,ps + l);
	solve(ir+1,ie,ps + l + 1,pe-1);
}
int main(void){
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++) scanf("%d",&inorder[i]);
	for(int i = 0 ; i < N ; i++) scanf("%d",&postorder[i]);
	for(int i = 0 ; i < N ; i++)
		position[inorder[i]] = i;
	
	int is = 0, ie = N-1, ps = 0, pe = N-1;
	solve(is,ie,ps,pe);
	printf("\n");
	return 0;
}

