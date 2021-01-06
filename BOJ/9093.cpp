#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin >> t;
    cin.ignore();

    while(t--){
        string str;
        getline(cin,str);
        
        str += '\n';
        stack<char> stk;

        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] == ' ' || str[i] == '\n'){
                while(!stk.empty()){
                    cout << stk.top();
                    stk.pop();
                }
                cout << str[i];
            }else{
                stk.push(str[i]);
            }
        }
    }
    return 0;
}
