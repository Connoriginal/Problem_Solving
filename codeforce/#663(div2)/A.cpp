#include <iostream>

using namespace std;

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cout << i << " ";
    cout << '\n';
  }
  return 0;
}
