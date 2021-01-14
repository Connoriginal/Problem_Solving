#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n,d;
        cin >> n >> d;

        bool flag = true;
        vector<int> a;
        for(int i = 1 ; i <= n ; i++){
            int tmp;
            cin >> tmp;

            if(tmp <= d){
                a.push_back(tmp);
            }else{
                flag = false;
            }
        }

        sort(a.begin(),a.end());

        if(flag || a.size() > 1 && a[0] + a[1] <= d) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
