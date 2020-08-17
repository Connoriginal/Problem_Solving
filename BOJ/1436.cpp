#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main(void){
  int n;
  scanf("%d",&n);

  int num = 665;
  int series = 0;

  while(num++){
    string str = to_string(num);

    for(int i = 0 ; i < str.length() - 2 ; i++){
      if(str[i] == '6' && str[i+1] == '6' && str[i+2] == '6'){

        series++;

        if(series == n){
          printf("%d\n",num);
          return 0;
        }
        break;
      }
    }
  }

  return 0;
}
