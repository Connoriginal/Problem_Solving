#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> vec(n);
    stack<pair<int,int> > stk;

    for(int i = 0 ; i < n ; i++){
        cin >> vec[i];

        while(!stk.empty() && stk.top().second < vec[i]){
            int idx = stk.top().first;
            vec[idx] = vec[i];
            stk.pop();
        }

        stk.push(make_pair(i,vec[i]));
        vec[i] = -1;
    }

    for(int i = 0 ; i < n ; i++){
        cout << vec[i] << ' ';
    }
    cout << '\n';

    return 0;
}

/* not using pair 

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> vec(n),ans(n);
    stack<int> stk;

    for(int i = 0 ; i < n ; i++){
        cin >> vec[i];

        while(!stk.empty() && vec[stk.top()] < vec[i]){
            ans[stk.top()] = vec[i];
            stk.pop();
        }

        stk.push(i);
        ans[i] = -1;
    }

    for(int i = 0 ; i < n ; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}

*/