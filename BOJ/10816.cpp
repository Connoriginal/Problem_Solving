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

int arr[500001];
int N,M;

int main(void){
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++)
		scanf("%d",&arr[i]);

	sort(arr,arr+N);

	scanf("%d",&M);
	while(M--){
		int x;
		scanf("%d",&x);
		auto up = upper_bound(arr,arr+N,x);
		auto lo = lower_bound(arr,arr+N,x);
		printf("%ld ",up - lo);
	}
	printf("\n");
	return 0;
}

/* 다른 version
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main(void){
  int n;
  scanf("%d",&n);
  vector<int> a(n);

  for(int i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }

  sort(a.begin(),a.end());

  int m;
  scanf("%d",&m);
  while(m--){
    int temp;
    scanf("%d",&temp);
    cout << upper_bound(a.begin(),a.end(),temp) - lower_bound(a.begin(),a.end(),temp) << " ";
  }
  printf("\n");
  return 0;
}
*/
