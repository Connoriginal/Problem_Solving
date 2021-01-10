#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int pri(char c){
    if(c == '(') return 0;
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string str;
    cin >> str;

    string ans = "";
    stack<char> stk;

    for(char c : str){
        if('A' <= c && c <= 'Z'){
            ans += c;
        }else if(c == '('){
            stk.push(c);
        }else if(c == ')'){
            while(stk.top() != '('){
                ans += stk.top();
                stk.pop();
            }
            stk.pop();
        }else{
            while(!stk.empty() && pri(stk.top()) >= pri(c)){
                ans += stk.top();
                stk.pop();
            }
            stk.push(c);
        }

    }

    while(!stk.empty()){
        ans += stk.top();
        stk.pop();
    }

    cout << ans << '\n';
    return 0;
}
