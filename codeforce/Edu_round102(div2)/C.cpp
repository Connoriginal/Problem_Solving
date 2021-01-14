#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;

        vector<int> a(n+1);
        for(int i = 1 ; i <= k ; i++) a[i] = i;
        for(int i = k+1 ; i <= n ; i++) a[i] = 2*k - i;

        int a_num = n-k;
        vector<int> p(k+1);
        for(int i = 1 ; i <= k ; i++) p[i] = i;

        reverse(p.begin()+k-a_num,p.end());

        for(int i = 1 ; i <= k ; i++){
            cout << p[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
