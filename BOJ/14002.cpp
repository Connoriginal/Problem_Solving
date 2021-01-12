#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int a[1001];
int d[1001];
int pre[1001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        d[i] = 1;pre[i] = -1;
    }

    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(a[i] > a[j] && d[i] < d[j] + 1){
                d[i] = d[j] + 1;
                pre[i] = j;
            }
        }
    }

    int len = 1, lst = 0;
    for(int i = 0 ; i < n ; i++){
        if(d[i] > len){
            len = d[i];
            lst = i;
        }
    }

    if(len == 1){
        cout << len << '\n' << a[0] << '\n';
        return 0;
    }

    stack<int> stk;
    
    while(lst!=-1){
        stk.push(lst);
        lst = pre[lst];
    }

    cout << stk.size() << '\n';
    while(!stk.empty()){
        cout << a[stk.top()] << ' ';
        stk.pop();
    }
    cout << '\n';
    
    return 0;
}
