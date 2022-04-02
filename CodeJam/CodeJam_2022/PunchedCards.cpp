#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int test_case;

int main(void){
  scanf("%d",&test_case);
  for(int i = 1 ; i <= test_case ; i++){
    printf("Case #%d:\n",i);

    int r,c; 
    scanf("%d %d",&r,&c);
    for(int j = 0 ; j < 2*r + 1 ; j++){
        for(int k = 0 ; k < c + 1 ; k++){
            if(j <=1 && k == 0){
                printf("..");
                continue;
            }

            if(k == c){
                if(j & 1) printf("|");
                else printf("+");
            }
            else{
                if(j & 1) printf("|.");
                else printf("+-");
            }
            
        }
        printf("\n");
    }
  }

  return 0;
}
