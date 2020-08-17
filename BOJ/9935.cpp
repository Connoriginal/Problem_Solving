#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

char txt[1000001];
char word[100];
bool erased[1000001];
stack<pair<int,int>> stk;

int main() {
	scanf("%s",txt);
	scanf("%s",word);
	int n = strlen(txt);
	int m = strlen(word);

	if(m==1){
		for(int i = 0 ; i < n ; i++){
			if(txt[i] == word[0])
				erased[i] = true;
		}
	}
	else{
		for(int i = 0 ; i < n ; i++){
			if(txt[i] == word[0])
				stk.push(make_pair(i,0));
			else{
				if(!stk.empty()){
					auto p = stk.top();
					if(txt[i] == word[p.second+1]){
						stk.push(make_pair(i,p.second+1));
						if(p.second+1 == m-1){
							for(int j = 0 ; j < m ; j++){
								erased[stk.top().first] = true;
								stk.pop();
							}
						}
					}
					else{
						while(!stk.empty())
							stk.pop();
					}
				}
			}
		}
	}


	bool left = false;
	for(int i = 0 ; i < n ; i++){
		if(erased[i]) continue;
		left = true;
		printf("%c",txt[i]);
	}

	if(!left)
		printf("FRULA");
	printf("\n");
    return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

char txt[1000001];
char a[50];
bool erase[1000001];

int main(void){
  scanf("%s %s",txt,a);
  int tlen = strlen(txt);
  int alen = strlen(a);
  stack<pair<int,int> > stk;

  if(alen == 1){
    for(int i = 0 ; i < tlen ; i++){
      if(txt[i] == a[0]) erase[i] = true;
    }
  }
  else{
    for(int i = 0 ; i < tlen ; i++){
      if(txt[i] == a[0]){
        stk.push(make_pair(0,i));
      }
      else if(!stk.empty()){
        int p = stk.top().first;
        if(a[p+1] == txt[i]){
          stk.push(make_pair(p+1,i));
          if(p+1 == alen - 1){
            for(int i = 0 ; i < alen ; i++){
              erase[stk.top().second] = true;
              stk.pop();
            }
          }
        }
        else{
          while(!stk.empty()){
            stk.pop();
          }
        }
      }
    }
  }

  bool check = true;

  for(int i = 0 ; i < tlen ; i++){
    if(!erase[i]){
      check = false;
      printf("%c",txt[i]);
    }
  }

  if(check) printf("FRULA");
  printf("\n");
  return 0;
}
*/
