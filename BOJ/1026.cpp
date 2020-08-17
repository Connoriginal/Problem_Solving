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

bool cmp(const int &u, const int &v){
	return u > v;
}

int main(void){
	int N;
	scanf("%d",&N);
	vector<int> a(N),b(N);
	for(int i = 0 ; i < N ; i++)
		scanf("%d",&a[i]);
	for(int i = 0 ; i < N ; i++)
		scanf("%d",&b[i]);
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end(),cmp);
	
	int S = 0;
	for(int i = 0 ; i < N ; i++){
		S += a[i] * b[i];
	}
	printf("%d\n",S);
	return 0;
}

