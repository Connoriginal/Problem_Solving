#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int>> q;

int main(void){
  int n;
  scanf("%d",&n);
  while(n--){
    int tmp;
    scanf("%d",&tmp);

    if(!tmp){
      if(q.empty()) printf("0\n");
      else{
        printf("%d\n",q.top());
        q.pop();
      }
    }
    else{
      q.push(tmp);
    }
  }
  return 0;
}

/*구현
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>


using namespace std;

int heap[100001];
int hn;

int pop(){
	int ans = heap[1];
	heap[1] = heap[hn];
	heap[hn--] = INT_MAX;
	for(int i = 1 ; i * 2 <= hn; ){
		if(heap[i] < heap[i*2] && heap[i] < heap[i*2 + 1])
			break;
		else if(heap[i*2] < heap[i*2 + 1]){
			swap(heap[i],heap[i*2]);
			i = i * 2;
		}
		else{
			swap(heap[i],heap[i*2 + 1]);
			i = i*2 + 1;
		}
	}
	return ans;
}

void push(int x){
	heap[++hn] = x;
	for(int i = hn ; i > 1 ; i /= 2){
		if(heap[i/2] > heap[i]){
			swap(heap[i/2],heap[i]);
		}
		else
			break;
	}
}

int main(void){
	int t;
	scanf("%d",&t);
	heap[1] = INT_MAX;
	while(t--){
		int tmp;
		scanf("%d",&tmp);
		if(tmp == 0){
			if(hn == 0)
				printf("0\n");
			else
				printf("%d\n",pop());
		}
		else
			push(tmp);
	}


	return 0;
}
*/
