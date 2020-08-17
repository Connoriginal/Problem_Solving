#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main(void){
  string str;
  cin >> str;

  vector<int> pl;
  vector<int> mi;

  bool plus = true;
  int left = 0;
  for(int pos = 0 ; pos <= str.size() ; pos++){

    if(str[pos] == '-' || str[pos] == '+' || pos == str.size()){
      if(plus){
        pl.push_back(stoi(string(str.begin()+left,str.begin()+pos)));
      }
      else{
        mi.push_back(stoi(string(str.begin()+left,str.begin()+pos)));
      }
      left = pos + 1;
    }

    if(str[pos] == '-'){
      plus = false;
    }

  }

  int ans = 0;
  for(int i = 0 ; i < pl.size() ; i++){
    ans += pl[i];
  }

  for(int i = 0 ; i < mi.size() ; i++){
    ans -= mi[i];
  }

  printf("%d\n",ans);
  return 0;
}
