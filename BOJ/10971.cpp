#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int W[11][11];

int main(void){
	int N;
	scanf("%d",&N);
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++)
			scanf("%d",&W[i][j]);
	}

	vector<int> vec(N);
	for(int i = 0 ; i < N ; i++)
		vec[i] = i+1;

	int ans = 100000000;
	do{
		bool check = true;
		int tmp = 0;
		for(int i = 0 ; i < N-1 ; i++){
			if(W[vec[i]][vec[i+1]] == 0){
				check = false;
				break;
			}
			tmp += W[vec[i]][vec[i+1]];
		}

		if(W[vec[N-1]][vec[0]] != 0 && check){
			tmp += W[vec[N-1]][vec[0]];
			ans = min(ans,tmp);
		}
	}while(next_permutation(vec.begin()+1,vec.end()));

	printf("%d\n",ans);
	return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int w[11][11];
int n;

int cal(vector<int> a){
  int ans = 0;
  for(int i = 0 ; i < a.size()-1 ; i++){
    if(w[a[i]][a[i+1]] == 0) return -1;
    ans += w[a[i]][a[i+1]];
  }

  if(w[a[a.size()-1]][a[0]] == 0) return -1;
  ans += w[a[a.size()-1]][a[0]];
  return ans;
}

int main() {
  scanf("%d",&n);
  for(int i = 1; i <= n ; i++){
    for(int j = 1 ; j <= n ; j++){
      scanf("%d",&w[i][j]);
    }
  }

  vector<int> a(n);
  for(int i = 0 ; i < n ; i++) a[i] = i+1;

  int ans = cal(a);
  while(next_permutation(a.begin(),a.end())){
    int temp = cal(a);
    if(ans == -1 || (temp < ans && temp > 0)){
      ans = temp;
    }
  }

  printf("%d\n",ans);
  return 0;
}
*/
