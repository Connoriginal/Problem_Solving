#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int a[100001];

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,s;
    cin >> n >> s;

    for(int i = 0 ; i < n ; i++){
        int tmp;
        cin >> tmp;
        a[i] = abs(tmp - s);
    } 

    int ans = a[0];
    for(int i = 1 ; i < n ; i++){
        ans = gcd(ans,a[i]);
    }

    cout << ans << '\n';
    return 0;
}
