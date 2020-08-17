#include <iostream>
#include <string>
#include <set>

using namespace std;


int main(void){
  int N,M;
  scanf("%d %d",&N,&M);
  set<string> non_see,both;
  for(int i = 0 ; i < N ; i++){
    string str;
    cin >> str;
    non_see.insert(str);
  }

  for(int i = 0 ; i < M ; i++){
    string str;
    cin >> str;
    if(non_see.find(str) != non_see.end()){
      both.insert(str);
    }
  }

  printf("%lu\n",both.size());
  set<string>::iterator iter;
  for(iter = both.begin() ; iter != both.end() ; iter++){
    cout << *iter << '\n';
  }
  return 0;
}

/*ver 2
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;


int main(void){
  int n,m;
  scanf("%d %d",&n,&m);
  set<string> a,ans;
  for(int i = 0 ; i < n ; i++){
    string tmp;
    cin >> tmp;
    a.insert(tmp);
  }
  for(int i = 0 ; i < m ; i++){
    string tmp;
    cin >> tmp;
    if(a.count(tmp) > 0) ans.insert(tmp);
  }

  printf("%lu\n",ans.size());
  set<string>::iterator iter;
  for(iter = ans.begin() ; iter != ans.end() ; iter++){
    cout << *iter << '\n';
  }
  return 0;
}
*/
