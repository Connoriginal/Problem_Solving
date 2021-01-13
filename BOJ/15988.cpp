#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1000000009;

long long d[1000001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    d[1] = 1;d[2] = 2;d[3]=4;

    for(int i = 4; i <= 1000000 ; i++){
        d[i] = (d[i-1] + d[i-2] + d[i-3])%mod;
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << d[n] % mod <<'\n';
    }
    return 0;
}
