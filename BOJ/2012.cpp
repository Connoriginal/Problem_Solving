#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n+1,0);

    for(int i = 1 ; i <= n ; i++) cin >> arr[i];

    sort(arr.begin(),arr.end());

    long long ans = 0;
    for(int i = 1 ; i <= n ; i++){
        ans += abs(arr[i] - i);
    }
    cout << ans << '\n';

    return 0;
}
