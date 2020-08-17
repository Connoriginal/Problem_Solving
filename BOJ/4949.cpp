#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;



int main(void){
  while(true){
    stack<char> stk;
    string str;
    getline(cin,str);

    //종료 조건
    if(str == "."){
      break;
    }

    bool check = true;
    for(int i = 0 ; i < str.size() ; i++){

      if(str[i] == '{' || str[i] == '[' || str[i] == '('){
        stk.push(str[i]);
      }

      if(str[i] == '}'){
        if(!stk.empty() && stk.top() == '{') stk.pop();
        else{
          check = false;
          break;
        }
      }

      if(str[i] == ']'){
        if(!stk.empty() && stk.top() == '[') stk.pop();
        else{
          check = false;
          break;
        }
      }

      if(str[i] == ')'){
        if(!stk.empty() && stk.top() == '(') stk.pop();
        else{
          check = false;
          break;
        }
      }
    }

    if(check && stk.empty()) printf("yes\n");
    else{
      printf("no\n");
    }
  }
  return 0;
}
