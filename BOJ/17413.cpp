#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    string str;
    getline(cin,str);
    str += '\n';

    stack<char> stk;
    queue<char> que;
    for(char ch : str){
        if(!que.empty()){
            que.push(ch);
            if(ch == '>'){
                while(!que.empty()){
                    cout << que.front();
                    que.pop();
                }
            }
        }else{
            if(ch == ' ' || ch == '\n' || ch == '<'){
                while(!stk.empty()){
                    cout << stk.top();
                    stk.pop();
                }
                if(ch == '<'){
                    que.push(ch);
                }else{
                    cout << ch;
                }
            }else{
                stk.push(ch);
            }   
        } 
    }
    return 0;
}
