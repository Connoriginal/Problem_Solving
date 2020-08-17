#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack>

using namespace std;

int T;
char S[101];

int main(void){
  scanf("%d",&T);
  for(int test_case = 1 ; test_case <= T ; test_case++){
    stack<int> st;
    scanf("%s",S);

    string ans = "";

    int num = strlen(S);
    for(int i = 0 ; i < num ; i++){
      int temp = S[i] - '0';

      if(st.empty()){
        for(int j = 0 ; j < temp ; j++){
          ans +='(';
        }
        st.push(temp);
      }
      else{
        if(st.top() > temp){
          ans += to_string(st.top());
          for(int j = 0 ; j < st.top() - temp ; j++){
            ans += ')';
          }
          st.pop();
          st.push(temp);
        }
        else if(st.top() == temp){
          ans += to_string(temp);
        }
        else{
          ans += to_string(st.top());
          for(int j = 0 ; j < temp - st.top() ; j++){
            ans += '(';
          }
          st.pop();
          st.push(temp);
        }
      }
    }

    ans += to_string(st.top());
    for(int i = 0 ; i < st.top() ; i++){
      ans += ')';
    }


    printf("Case #%d: ",test_case);
    cout << ans << '\n';
  }
  return 0;
}
