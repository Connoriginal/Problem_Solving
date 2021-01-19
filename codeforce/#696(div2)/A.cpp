#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string b;
        cin >> b;
        string a = "";

        char prev = b[0];
        if(prev == '1'){
            a += '1';
            prev = '2';
        }else{
            a += '1';
            prev = '1';
        }

        for(int i = 1; i < n ; i++){
            char c = b[i];
            if(c == '1'){
                if(prev == '2'){
                    a += '0';
                    prev = '1';
                }else{
                    a += '1';
                    prev = '2';
                }
            }else{
                if(prev == '1'){
                    a += '0';
                    prev = '0';
                }else{
                    a += '1';
                    prev = '1';
                }
            }
        }
        cout << a << '\n';

    }
    return 0;
}
