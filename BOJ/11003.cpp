#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;


int main(void){
  int n,k;
  scanf("%d %d",&n,&k);

  vector<int> arr(n);
  deque<pair<int,int> > dq;

  for(int i = 0 ; i < n ; i++) scanf("%d",&arr[i]);

  int l = 0, r = 0;
  dq.push_back(make_pair(arr[0],0));
  printf("%d ",arr[0]);
  while(r < n-1){
    if(r - l == k - 1) l++;
    r++;
    while(!dq.empty() && dq.back().first >= arr[r]) dq.pop_back();
    dq.push_back(make_pair(arr[r],r));

    if(!(l <= dq.front().second && dq.front().second <= r)) dq.pop_front();
    printf("%d ", dq.front().first);
  }
  printf("\n");
  return 0;
}

/* priority_queue 사용 (메모리 더 사용, 시간 단축)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,k;
  cin >> n >> k;

  vector<int> arr(n), ans(n);
  for(int i = 0 ; i < n ; i++) cin >> arr[i];

  ans[0] = arr[0];

  priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int, int> > > pq;
  int l = 0, r = 0;
  pq.push(make_pair(arr[0],0));
  while(r < n - 1){
    if(r - l == k - 1) l++;
    r++;
    pq.push(make_pair(arr[r],r));
    while(true){
      if(l <= pq.top().second && pq.top().second <= r) break;
      pq.pop();
    }
    ans[r] = pq.top().first;
  }

  for(int i = 0 ; i < n ; i++) cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}
*/
