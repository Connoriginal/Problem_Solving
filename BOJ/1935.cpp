#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    string str;
    vector<int> vec(n);
    stack<double> stk;

    cin >> str;
    for(int i = 0 ; i < n ; i++) cin >> vec[i];

    for(char c : str){
        if('A' <= c && c <= 'Z') stk.push(vec[c-'A']);
        else{
            double sec = stk.top();stk.pop(); 
            double fst = stk.top();stk.pop();

            if(c == '+') stk.push(fst+sec);
            else if(c == '-') stk.push(fst-sec);
            else if(c == '*') stk.push(fst*sec);
            else stk.push(fst/sec);
        }
        
    }

    cout << fixed;
    cout.precision(2);
    cout << stk.top() << '\n';
    cout.unsetf(ios::fixed);
    return 0;
}
