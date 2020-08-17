#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    vector<string> map(n+1);
    for(int i = 0 ; i < n ; i++){
      cin >> map[i];
    }

    int cnt = 0;
    for(int i = 0 ; i < n-1 ; i++){
      if(map[i][m-1] == 'R') cnt++;
    }
    for(int i = 0 ; i < m-1 ; i++){
      if(map[n-1][i] == 'D') cnt++;
    }

    cout << cnt << '\n';
  }
  return 0;
}
