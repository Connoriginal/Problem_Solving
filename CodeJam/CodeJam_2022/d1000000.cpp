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

        int N;
        cin >> N;

        vector<int> vec(N);
        for(int i = 0 ; i < N ; i++){
            cin >> vec[i];
        }

        sort(vec.begin(), vec.end());

        int ans = 0;

        int line = 1, vec_ptr = 0;

        int flag = 0;
        while(line <= N && vec_ptr < N){
            while(vec[vec_ptr] >= line){
                vec_ptr++;line++;ans++;
                if(vec_ptr >= N){
                    flag = 1;
                    break;
                }
            }

            if(flag == 1) break;

            while(vec[vec_ptr] < line){
                vec_ptr++;
                if(vec_ptr >= N){
                    flag = 1;
                    break;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}