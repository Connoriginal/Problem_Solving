#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main(void){
  int T;
  scanf("%d",&T);
  for(int test_case = 1 ; test_case <= T ; test_case++){
    int n,m;

    scanf("%d",&n);
    vector<int> note1(n);
    for(int i = 0 ; i < n ; i++) scanf("%d",&note1[i]);
    sort(note1.begin(),note1.end());

    scanf("%d",&m);
    for(int i = 0 ; i < m ; i++){
      int tmp;
      scanf("%d",&tmp);
      printf("%d\n",binary_search(note1.begin(),note1.end(),tmp));
    }
  }
  return 0;
}
