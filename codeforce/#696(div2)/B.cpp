#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int prime[100001];


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    for(int i = 2 ; i <= 100000 ; i++){
        if(prime[i]) continue;
        for(int j = i*2 ; j <= 100000 ; j+=i){
            prime[j] = true;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int d;
        cin >> d;

        long long a = 1+d;
        while(prime[a])a++;
        long long b = a+d;
        while(prime[b])b++;
        cout << a*b << '\n';
    }
    return 0;
}
