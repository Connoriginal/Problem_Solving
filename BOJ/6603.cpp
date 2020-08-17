#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    while (true) {
		int N;
		scanf("%d",&N);
		if(N == 0) break;
		vector<int> vec(N);
		for(int i = 0 ; i < N ; i++)
			scanf("%d",&vec[i]);

		vector<vector<int>> ans;

		vector<int> tmp;
		for(int i = 0 ; i < 6 ; i++) tmp.push_back(0);
		for(int i = 0 ; i < N-6 ; i++) tmp.push_back(1);

		do{
			vector<int> curr;
			for(int i = 0 ; i < N ; i++){
				if(tmp[i] == 0) curr.push_back(vec[i]);
			}

			ans.push_back(curr);
		}while(next_permutation(tmp.begin(),tmp.end()));

		sort(ans.begin(),ans.end());

		for(auto &v : ans){
			for(int i = 0 ; i < 6 ; i++)
				printf("%d ",v[i]);
			printf("\n");
		}
		printf("\n");
	}
    return 0;
}

/* version2
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int arr[13];
int com[13];

int main() {
  int k;
  for(int i = 0 ; i < 6 ; i++) com[i] = 1;

  while(scanf("%d",&k)){
    if(k == 0) break;
    sort(com,com+k,greater<int>());
    for(int i = 0 ; i < k ; i++){
      scanf("%d",&arr[i]);
    }

    do{
      for(int i = 0 ; i < k ; i++){
        if(com[i] == 1){
          printf("%d ",arr[i]);
        }
      }
      printf("\n");
    }while(prev_permutation(com,com+k));



    printf("\n");
  }
  return 0;
}
*/
