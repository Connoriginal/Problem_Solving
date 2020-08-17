#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

priority_queue<int> que;

int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int tmp;
		scanf("%d",&tmp);
		if(tmp == 0){
			if(que.empty())
				printf("0\n");
			else{
				printf("%d\n",que.top());
				que.pop();
			}
		}
		else{
			que.push(tmp);
		}
	}
	return 0;
}

/* 구현 한것
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int heap[100010];
int hp = 1;


void swap(int idx1, int idx2){
  int tmp = heap[idx1];
  heap[idx1] = heap[idx2];
  heap[idx2] = tmp;
}

void erase(void){
  printf("%d\n",heap[1]);
  if(hp > 1){
    swap(1,--hp);
    heap[hp] = 0;
  }
  for(int idx = 1 ; idx * 2 <= hp ; ){
    if(heap[idx] > heap[idx*2] && heap[idx] > heap[idx*2+1]) break;
    if(heap[idx*2] > heap[idx*2 + 1]){
      swap(idx,idx*2);
      idx = idx*2;
    }
    else{
      swap(idx,idx*2 + 1);
      idx = idx*2 + 1;
    }
  }
}

void add(int x){
  heap[hp++] = x;
  for(int idx = hp-1 ; idx > 1 ; idx /= 2){
    if(heap[idx] < heap[idx/2]) break;
    else swap(idx,idx/2);
  }
}

int main(void){
  int n;
  scanf("%d",&n);

  while(n--){
    int tmp;
    scanf("%d",&tmp);
    if(tmp == 0){
      erase();
    }
    else{
      add(tmp);
    }
  }
  return 0;
}
*/
