#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<float> child,parent;

    for(int i = 0 ; i < 2 ; i++){
        int tmp;
        cin >> tmp;
        child.push_back(tmp);
    }

    for(int i = 0 ; i < 2 ; i++){
        int tmp;
        cin >> tmp;
        parent.push_back(tmp);
    }

    int ans = 0;
    float cal = 0;

    for(int turn = 0 ; turn < 4 ; turn++){
        float tmp = 0;
        for(int i = 0 ; i < 2 ; i++){
            tmp += child[i]/parent[i];
        }

        if(tmp > cal){
            ans = turn;
            cal = tmp;
        } 

        parent.push_back(child.back());
        child.pop_back();
        child.push_front(parent.front());
        parent.pop_front();

    }

    cout << ans << '\n';
    return 0;
}
