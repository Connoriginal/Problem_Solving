#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b;
    char t;
    cin >> a >> t >> b;
    int g = gcd(a,b);

    cout <<a/g << ":"<<b/g << '\n';
    return 0;
}

/* c 스타일
int main(void){
    int a,b;
    scanf("%d:%d",&a,&b);
    int g = gcd(a,b);

    printf("%d:%d\n",a/g,b/g);
    return 0;
}
*/