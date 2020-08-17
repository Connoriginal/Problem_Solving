#include <iostream>
#include <cstdio>
#include <set>
#include <string>

using namespace std;


int t;

int main(void){
  scanf("%d",&t);
  set<string> conf;
  while(t--){
    string name, act;
    cin >> name >> act;
    if(act == "enter"){
      conf.insert(name);
    }
    else if(act == "leave"){
      conf.erase(conf.find(name));
    }
  }
  set<string>::reverse_iterator iter;
  for(iter = conf.rbegin(); iter != conf.rend() ; iter++){
    cout << *iter << '\n';
  }
  return 0;
}

/* ver2
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;


int main(void){
  int n;
  scanf("%d",&n);
  set<string,greater<string> > bst;
  while(n--){
    string name, op;
    cin >> name >> op;
    if(op == "enter"){
      bst.insert(name);
    }
    else{
      bst.erase(bst.lower_bound(name));
    }
  }
  set<string>::iterator iter;
  for(iter = bst.begin() ; iter != bst.end() ; iter++){
    cout << *iter << '\n';
  }
  return 0;
}
*/
