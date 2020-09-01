#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int alp[27];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;

      vector<string> vec(n);
      for(int i = 0 ; i < n ; i++){
        cin >> vec[i];
      }

      for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < vec[i].length() ; j++){
          int cur = vec[i][j] - 'a';
          alp[cur]++;
        }
      }

      bool flag = true;
      for(int i = 0 ; i < 27 ; i++){
        if(alp[i] % n != 0){
          flag = false;
          break;
        }
      }

      if(flag) cout << "YES" << '\n';
      else cout << "NO" << '\n';

      fill(&alp[0],&alp[26],0);
    }
    return 0;
}
