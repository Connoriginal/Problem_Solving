#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        long long n;
        cin >> n;
       
       int mod = 2020;

       int a = n / mod;
       int b = n % mod;
       if(a >= b) cout << "YES" << '\n';
       else cout << "NO" << '\n';

    }
    return 0;
}
