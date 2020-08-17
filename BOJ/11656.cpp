#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string str;
vector<int> arr;

bool compare(const int &u, const int &v){
  return strcmp(str.c_str() + u, str.c_str()+v) < 0;
}

int main(void){
  cin >> str;

  for(int i = 0 ; i < str.size() ; i++){
    arr.push_back(i);
  }

  sort(arr.begin(), arr.end() , compare);

  for(auto &x : arr){
    cout << str.substr(x) << '\n';
  }
  return 0;
}
