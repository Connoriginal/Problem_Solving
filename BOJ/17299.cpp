#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int val[1000001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n),b(n);
    stack<pair<int,int> > stk;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        val[a[i]]++;
    }

    for(int i = 0 ; i < n ; i++) b[i] = val[a[i]];
    
    for(int i = 0 ; i < n ; i++){
        while(!stk.empty() && stk.top().second < b[i]){
            int idx = stk.top().first;
            a[idx] = a[i];
            stk.pop();
        }

        a[i] = -1;
        stk.push(make_pair(i,b[i]));
    }

    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}

/* Not Using Pair

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n),b(n);
    stack<int> stk;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        val[a[i]]++;
    }

    for(int i = 0 ; i < n ; i++) b[i] = val[a[i]];
    
    for(int i = 0 ; i < n ; i++){
        while(!stk.empty() && b[stk.top()] < b[i]){
            a[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
        a[i] = -1;
    }

    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}

*/