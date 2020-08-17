#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

char a[16];
int l,c;

bool check(string str){
  int vn = 0 , cn = 0;
  for(char &p : str){
    if(p == 'a' || p == 'e' || p == 'i' || p == 'o' || p == 'u'){
      vn++;
    }
    else{
      cn++;
    }
  }
  if(vn >= 1 && cn >= 2) return true;
  return false;
}

void solve(string str, int p){
  if(p > c) return;
  if(str.size() > l) return;
  if(str.size() == l){
    if(check(str)){
      cout << str << '\n';
    }
    return;
  }
  solve(str + a[p],p+1);
  solve(str,p+1);
  return;
}
int main(void) {
  scanf("%d %d",&l,&c);
  for(int i = 0 ; i < c ; i++){
    scanf(" %c",&a[i]);
  }

  sort(a,a+c);

  solve("",0);
  return 0;
}

/* 노가다 version
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char vow[16];
char con[16];
int vp = 0, cp = 0;
vector<string> vec;

void solve(int vnum, int cnum){
  vector<int> v;
  vector<int> c;
  for(int i = 0 ; i < vnum ; i++){
    v.push_back(1);
  }
  for(int i = vnum ; i < vp ; i++){
    v.push_back(0);
  }
  for(int i = 0 ; i < cnum ; i++){
    c.push_back(1);
  }
  for(int i = cnum ; i < cp ; i++){
    c.push_back(0);
  }


  do{
    string str = "";
    for(int i = 0 ; i < vp ; i++){
      if(v[i] == 1){
        str += vow[i];
      }
    }

    do{
      string str2 = str;
      for(int i = 0 ; i < cp ; i++){
        if(c[i] == 1){
          str2 += con[i];
        }
      }
      sort(str2.begin(),str2.end());
      vec.push_back(str2);
    }while(prev_permutation(c.begin(),c.end()));
    sort(c.begin(),c.end(),greater<int>());
  }while(prev_permutation(v.begin(),v.end()));

  return;
}

int main(void) {
  int l,c;
  scanf("%d %d",&l,&c);



  for(int i = 0 ; i < c ; i++){
    char tmp;
    scanf(" %c",&tmp);
    if(tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u'){
      vow[vp++] = tmp;
    }
    else{
      con[cp++] = tmp;
    }
  }

  int vn = 1, cn = 2;
  l -= 3;
  for(int i = 0 ; i <= l ; i++){
    if(vn+i <= vp && cn + (l-i) <= cp)
      solve(vn+i, cn+(l-i));
  }

  sort(vec.begin(),vec.end());

  for(int i = 0 ; i < vec.size() ; i++){
    cout << vec[i] << '\n';
  }
  return 0;
}
*/
