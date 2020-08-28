#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      string str;
      cin >> str;
      for(int i = 0 ; i < n ; i++){
        cout << str[n-1];
      }
      cout << '\n';
    }
    return 0;
}
