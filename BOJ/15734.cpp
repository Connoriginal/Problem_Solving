#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int l,r,a;
    cin >> l >> r >> a;

    if(l > r) swap(l,r);

    while(l < r){
        if(a-- > 0) l++;
        else break;
    }

    cout << 2 * (l + a/2) << '\n';
    return 0;
}
