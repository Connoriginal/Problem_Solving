#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void){
  int n;
  scanf("%d",&n);

  unordered_map<string, int> m;
  for(int i = 0 ; i < n ; i++){
    string str;
    cin >> str;
    m[str] = i;
  }

  vector<string> vec(n);
  int ans = 0;
  for(int i = 0 ; i < n ; i++){
    cin >> vec[i];
  }

  for(int i = 0 ; i < n - 1 ; i++){
    for(int j = i + 1 ; j < n ; j++){
      if(m[vec[i]] > m[vec[j]]){
        ans++;
        break;
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}
