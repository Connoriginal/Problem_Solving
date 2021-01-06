#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[10];
bool b[10];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int sum = 0;
    for(int i = 0 ; i < 9 ; i++){
        cin >> a[i];
        sum += a[i];
        b[i] = true;
    } 

    sort(a,a+9);

    bool flag = true;

    for(int i = 0 ; i < 8 ; i++){
        for(int j = i+1 ; j < 9 ; j++){
            if(a[i] + a[j] == sum - 100){
                b[i] = false;b[j]=false;
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    
    for(int i = 0 ; i < 9 ; i++){
        if(b[i]) cout << a[i] << '\n';
    }
    return 0;
}

/*
int a[10];

int cnt(void){
    int cnt = 0;
    for(int i = 0 ; i < 7 ; i++) cnt += a[i];
    return cnt;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0 ; i < 9 ; i++) cin >> a[i];

    sort(a,a+9);

    int ans = cnt();
    while(next_permutation(a,a+9) && ans != 100){
        ans = cnt();
    }

    for(int i = 0 ; i < 7 ; i++){
        cout << a[i] << '\n';
    }
    return 0;
}
*/