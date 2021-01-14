#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int lcm(int a, int b){
    int g = gcd(a,b);
    a = a/g;
    b = b/g;
    return a*b*g;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        string s,t;
        cin >> s >> t;
        int l = lcm(s.size(),t.size());
        string left = "", right = "";
        for(int i = 0 ; i < l/s.size() ; i++){
            left += s;
        }
        for(int i = 0 ; i < l/t.size() ; i++){
            right += t;
        }

        if(left == right) cout << left << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}
