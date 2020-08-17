#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;



int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;

    vector<int> arr(n+1), ind(n+1,0);
    vector<vector<int> > edge(n+1);

    for(int i = 1 ; i <= n ; i++) cin >> arr[i];

    for(int i = 1 ; i < n ; i++){
      for(int j = i + 1 ; j <= n ; j++){
        ind[arr[j]]++;
      }
    }

    int m;
    cin >> m;
    while(m--){
      int u,v;
      cin >> u >> v;

      int x,y;
      for(int i = 1 ; i <= n ; i++){
        if(arr[i] == u){
          x = u; y = v;
          break;
        }else if(arr[i] == v){
          x = v; y = u;
          break;
        }
      }

      ind[x]++; ind[y]--;
    }

    queue<int> que;
    bool ans = true;
    for(int i = 0 ; i < n ; i++){
      bool flag = false;
      for(int j = 1 ; j <= n ; j++){
        if(ind[j] == i){
          if(!flag){
            flag = true;
            que.push(j);
          }else{
            ans = false;
            break;
          }
        }
      }
    }

    if(ans){
      while(!que.empty()){
        cout << que.front() << " ";
        que.pop();
      }
      cout << '\n';
    }else{
      cout << "IMPOSSIBLE" << '\n';
    }
  }
  return 0;
}
