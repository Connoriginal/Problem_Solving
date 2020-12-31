#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int len = 2;
    while(n--){
        len += len - 1;
    }

    cout << len*len << '\n';
    return 0;
}
