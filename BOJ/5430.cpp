#include <iostream>
#include <cstdio>
#include <string>
#include <deque>

using namespace std;

int t;

int main(void){
  scanf("%d",&t);
  while(t--){
    string func,str;
    int n;
    cin >> func >> n >> str;

    //입력 받기
    deque<int> deq(n);
    int pt = 0;

    for(int i = 1 ; i < str.size() ; i++){
      if('0' <= str[i] && str[i] <='9'){
        int temp = str[i] - '0';
        if('0' <= str[i-1] && str[i-1] <= '9'){
          deq[pt-1] = 10*deq[pt-1] + temp;
        }
        else{
          deq[pt++] = temp;
        }
      }
    }


    //함수실행
    bool error = false;
    bool up = true;
    for(char c : func){
      if(c == 'R'){
        up = !up;
      }
      else if(c == 'D'){
        if(deq.empty()){
          error = true;
          break;
        }
        if(up) deq.pop_front();
        else deq.pop_back();
      }
    }

    //출력
    if(error){
      printf("error\n");
    }
    else{
      printf("[");
      if(up){
        for(int i = 0 ; i < deq.size() ; i++){
          printf("%d",deq[i]);
          if(i != deq.size()-1) printf(",");
        }
      }
      else{
        for(int i = deq.size()-1 ; i >= 0 ; i--){
          printf("%d",deq[i]);
          if(i != 0) printf(",");
        }
      }
      printf("]\n");
    }
  }

  return 0;
}
