#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  string a,b;
  getline(cin,a);
  getline(cin,b);

  vector<int> pi(b.size(),0);

  for(int i = 1, j = 0 ; i <= b.size() ; i++){
    while(j>0 && b[i] != b[j]) j = pi[j-1];
    if(b[i] == b[j]) pi[i] = ++j;
  }


  for(int i = 0, j = 0 ; i <= a.size() ; i++){
    while(j > 0 && a[i] != b[j]) j = pi[j-1];
    if(a[i] == b[j]){
      if(j == b.size() - 1){
        cout << '1' << '\n';
        return 0;
      }else{
        j++;
      }
    }
  }

  cout << "0" << '\n';
  return 0;
}
