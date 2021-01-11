#include <iostream>
#include <algorithm>

using namespace std;

bool prime[1000001]; //false 가 소수


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    prime[1] = true;
    for(int i = 2 ; i < 1000000 ; i++){
        if(!prime[i]){
            for(int j = i*2 ; j <= 1000000; j += i){
                prime[j] = true;
            }
        }
    }

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        int ans = !prime[n-2];
        for(int i = 3 ; i <= n/2 ; i+=2){
            if(!prime[i] && !prime[n-i]){
                ans++;
            } 
        }
        cout << ans << '\n';
    }
    return 0;
}
