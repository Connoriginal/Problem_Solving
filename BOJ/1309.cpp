#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 9901;

int d[100001][3]; //아무곳도 안들어간거, 왼쪽만, 오른쪽만

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    d[0][0] = 1;d[0][1]=1;d[0][2]=1;

    for(int i = 1 ; i < n ; i++){
        d[i][0] = (d[i-1][0] + d[i-1][1] + d[i-1][2])%mod;
        d[i][1] = (d[i-1][0] + d[i-1][2])%mod;
        d[i][2] = (d[i-1][0] + d[i-1][1])%mod;
    }

    cout << (d[n-1][0] + d[n-1][1] + d[n-1][2]) % mod << '\n';

    return 0;
}
