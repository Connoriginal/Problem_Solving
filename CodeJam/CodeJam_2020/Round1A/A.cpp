#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int test_case;

int main(void){
  scanf("%d",&test_case);
  for(int i = 1 ; i <= test_case ; i++){
    int n;
    scanf("%d",&n);

    string inp;
    cin >> inp;

    for(int i = 0 ; i < n - 1 ; i++){
      string prev = inp;
      cin >> inp;



      for(int i = 0 ; i < prev.size() ; i++){

      }
    }



    printf("Case #%d : %s",test_case);
  }

  return 0;
}
