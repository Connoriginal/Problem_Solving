#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int main(void){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for(int test_case = 1 ; test_case <= T ; test_case++){
        cout << "Case #" << test_case << ": ";

        string inp;
        cin >> inp;
        int inp_size = inp.size();

        int pt = inp_size-1;
        char last_char = inp[pt];

        for(int i = inp_size-2 ; i >= 0 ; i--){
            if(inp[i] == last_char){
                pt = i;
            }
            else{
                break;
            }
        }

        string ans = "";

        for(int i = 0 ; i < pt ; i++){
            if(inp[i] < inp[i+1]){
                ans += inp[i];
            }
            if(inp[i] == inp[i+1]){
                int flag = 0;
                for(int j = i+1 ; j <= pt ; j++){
                    if(inp[i] != inp[j]){
                        flag = inp[i] < inp[j] ? 1 : 0;
                        break;
                    }
                }
                if(flag == 1){
                    ans += inp[i];
                }
            }
            ans += inp[i];
        }
        
        for(int i = pt ; i < inp_size ; i++){
            ans += inp[i];
        }

        cout << ans << '\n';
    }
    return 0;
}