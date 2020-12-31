#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;


    while(t--){
        int x,y;
        cin >> x >> y;

        y -= x;
        long long int i = 1;
        while(true){
            if(y <= i*i){
                cout << i*2-1 << '\n';
                break;
            }else if(y <= i*(i+1)){
                cout << i*2 << '\n';
                break;
            }
            i++;
        }
    }
    return 0;
}
