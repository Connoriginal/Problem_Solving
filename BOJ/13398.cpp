#include <iostream>
#include <algorithm>

using namespace std;

int a[100001];
int d[100001][2]; // 0: 제외x , 1: 한개제외


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }

    d[1][0] = a[1];d[1][1] = 0;

    for(int i = 2 ; i <= n ; i++){
        d[i][0] = max(a[i],d[i-1][0] + a[i]);
        d[i][1] = max(d[i-1][0],d[i-1][1] + a[i]);
    }
    
    int ans = max(d[1][0],d[1][1]);
    for(int i = 2; i <= n ; i++){
        int tmp = max(d[i][0],d[i][1]);
        ans = max(ans,tmp);
    }
    
    cout << ans << '\n';
    return 0;
}
