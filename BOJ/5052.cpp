#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);

    vector<string> vec(n);
    for(int i = 0 ; i < n ; i++){
      cin >> vec[i];
    }

    sort(vec.begin(),vec.end());

    bool flag = false;
    for(int i = 0 ; i < n-1 ; i++){
      if(vec[i].compare(vec[i+1].substr(0,vec[i].length())) == 0){
        flag = true;
        break;
      }
    }

    if(flag) printf("NO\n");
    else printf("YES\n");
  }
  return 0;
}

/* trie algorithm
#include <iostream>
#include <cstdio>

using namespace std;

struct Trie{
  bool finish; //이 노드에서 끝나는가?
  Trie *next[10]; //다음 노드를 가리키는 포인터배열

  //생성자
  Trie(){
    finish = false;
    for(int i = 0 ; i < 10 ; i++){
      next[i] = NULL;
    }
  }

  //소멸자
  ~Trie(){
    for(int i = 0 ; i < 10 ; i++){
      if(next[i]) delete next[i];
    }
  }

  //문자열 key를 현재노드부터 삽입, 삽입 후 일관성이 있는지를 리턴
  void insert(char *arr) {
    if(*arr == '\0'){
      finish = true;
    }else{
      int cur = *arr - '0'; //arr가 숫자라 index로 변환
      if(next[cur] == NULL){
        next[cur] = new Trie();
      }
      next[cur]->insert(arr+1);
    }
  }
  //문자열 key가 있는지를 확인
  bool find(char *arr){
    if(*arr == '\0') return false;

    if(finish) return true;

    int cur = *arr -'0';
    return next[cur]->find(arr+1);
  }
};

int main(void){
  int t;
  scanf("%d",&t);
  while(t--){
    char phone[10001][11];
    int n;
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++) scanf("%s",phone[i]);

    Trie *Root = new Trie();
    for(int i = 0 ; i < n ; i++) Root->insert(phone[i]);

    bool flag = false;
    for(int i = 0 ; i < n ; i++){
      if(Root->find(phone[i])){
        flag = true;
        break;
      }
    }

    if(!flag) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}

*/
