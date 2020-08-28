#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char str[100001];
bool check[100001];
char ans[100001];

int main(void){

    int t;
    scanf("%d",&t);
    while(t--){
      memset(ans,'1',sizeof(ans));
      memset(check,false,sizeof(check));

      scanf("%s",str);
      int x;
      scanf("%d",&x);

      int len = strlen(str);
      ans[len] = '\0';


      for(int i = 0 ; i < len ; i++){
        if(str[i] == '0'){
          if(i-x >=0) ans[i-x] = '0';
          if(i+x < len) ans[i+x] = '0';
        }
      }

      bool flag = false;
      for(int i = 0 ; i < len ; i++){
        if(str[i] == '1'){
          bool f = true;
          if(i - x >= 0){
            if(ans[i-x] != '0'){
              f = false;
            }
          }

          bool s = true;
          if(i + x < len){
            if(ans[i+x] != '0'){
              s = false;
            }
          }

          if(f&&s){
            flag = true;
            break;
          }
        }
      }

      if(flag){
        printf("-1\n");
      }else{
        printf("%s\n",ans);
      }
    }
    return 0;
}
