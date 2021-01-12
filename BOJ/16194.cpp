#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];
int p[1001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    fill(dp,dp+1000,10000000);
    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++) cin >> p[i];

    dp[0] = 0;
    dp[1] = p[1];

    for(int i = 2 ; i <= n ; i++){
        for(int j = 0 ; j <= i ; j++){
            dp[i] = min(dp[i],dp[i-j] + p[j]);        }
    }

    cout << dp[n] << '\n';
    return 0;
}
