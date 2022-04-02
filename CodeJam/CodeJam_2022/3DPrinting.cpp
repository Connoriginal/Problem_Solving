#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_COLOR = 1000000;

int T;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    for(int test_case = 1 ; test_case <= T ; test_case++){
        cout << "Case #" << test_case << ": ";

        int color[4];
        memset(color,MAX_COLOR,sizeof(color));
        int c,m,y,k;

        for(int i = 0 ; i < 3 ; i++){
            cin >> c >> m >> y >> k;
            color[0] = min(color[0],c);
            color[1] = min(color[1],m);
            color[2] = min(color[2],y);
            color[3] = min(color[3],k);
        }

        if(color[0] + color[1] + color[2] + color[3] < MAX_COLOR){
            cout << "IMPOSSIBLE\n";
            continue;
        }

        int tot = MAX_COLOR;

        for(int i = 0 ; i < 4 ; i++){
            if(tot <= 0){
                cout << "0 ";
                continue;
            } 

            if(color[i] < tot){
                cout << color[i] << " ";
                tot -= color[i];
            }
            else{
                cout << tot << " ";
                tot = 0;
            }
        }
        cout << '\n';
    }
    return 0;
}
