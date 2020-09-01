#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long check = 1;

    for(int i = 0 ; i < 63 ; i++) check *= 2;
    cout << check << '\n';
    return 0;
}
