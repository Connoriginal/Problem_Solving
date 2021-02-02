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

        bool flag = false;
        while(n % 2 == 0) n /= 2;

        if(n == 1) cout << "NO" << '\n';
        else cout << "YES" << '\n';

    }
    return 0;
}
