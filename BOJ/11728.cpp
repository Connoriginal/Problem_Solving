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

int N,M;

int main(void){
	scanf("%d %d",&N,&M);
	vector<int> a(N);
	vector<int> b(M);
	vector<int> ans(N+M);

	for(int i = 0 ; i < N ; i++)
		scanf("%d",&a[i]);
	for(int i = 0 ; i < M ; i++)
		scanf("%d",&b[i]);

	int l = 0, r = 0, k = 0;
	while(l < N && r < M){
		if(a[l] > b[r]){
			ans[k++] = b[r++];
		}
		else{
			ans[k++] = a[l++];
		}
	}

	while(l < N){
		ans[k++] = a[l++];
	}
	while(r < M){
		ans[k++] = b[r++];
	}

	for(int i = 0 ; i < k ; i++)
		printf("%d ",ans[i]);

	printf("\n");
	return 0;
}

/* 바로 나타내는 방식
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main(void){
  int n,m;
  scanf("%d %d",&n,&m);

  vector<int> a(n);
  vector<int> b(m);

  for(int i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }

  for(int i = 0 ; i < m ; i++){
    scanf("%d",&b[i]);
  }

  int i = 0, j = 0;
  while(i < n && j < m){
    if(a[i] <= b[j]){
      printf("%d ",a[i++]);
    }
    else{
      printf("%d ",b[j++]);
    }
  }

  if(i < n){
    while(i<n) printf("%d ",a[i++]);
  }

  if(j < m){
    while(j < m) printf("%d ",b[j++]);
  }
  printf("\n");
  return 0;
}
*/
